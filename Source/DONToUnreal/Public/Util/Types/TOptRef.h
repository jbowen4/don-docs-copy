// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#pragma warning(push)
#pragma warning( disable : 5030 )// disable "unrecognized attribute" warning for [[jetbrains::pass_by_value]]

#include "CoreMinimal.h"

/**
 * A nullable reference, but explicitly stated.
 *
 * Contains functions to act on the resulting value.
 *
 * @tparam T The type this reference points to. May be const. Untested when T is a reference itself.
 */
// ReSharper disable all CppNonExplicitConvertingConstructor Should allow implicit conversion
template<typename T>
class [[jetbrains::pass_by_value]] // Tells Resharper not to give "consider passing by const reference" warning
	DONTOUNREAL_API TOptRef
{
	T* ptr; // should be immutable
public:
	//region Constructors
	FORCEINLINE explicit TOptRef()
		: ptr(nullptr)
	{
	};

	FORCEINLINE TOptRef(T& ref)
		: ptr(&ref)
	{
	};

	// ReSharper disable once CppParameterMayBeConstPtrOrRef CANNOT be const, because we don't return a const reference unless T is a const type
	FORCEINLINE TOptRef(T* ptr)
		: ptr(ptr)
	{
	};

	// I'm praying no one tries to retain this... I don't know what to do here, because I want something like `foo(TOptRef(0))` to work since it'll be safe on the stack.
	FORCEINLINE TOptRef(T&& rvalRef)
		: ptr(&rvalRef)
	{
	};
	//endregion

	//region Checking Presence
	FORCEINLINE bool IsPresent() const noexcept
	{
		return ptr != nullptr;
	}

	FORCEINLINE bool IsAbsent() const noexcept
	{
		return ptr == nullptr;
	}

	FORCEINLINE operator bool() const noexcept
	{
		return IsPresent();
	}

	//endregion

	//region Get
	/**
	 * Get the contained reference if present.
	 *
	 * If absent, throws a `std::runtime_error` describing the error.
	 *
	 * @throws std::runtime_error If the value is absent.
	 */
	FORCEINLINE T& GetOrThrow() const
	{
		return GetOrThrow("TOptRef: Attempted to dereference null.");
	}

	/**
	 * Get the contained reference if present.
	 *
	 * If absent, throws a `std::runtime_error` with the provided error message.
	 * 
	 * @throws std::runtime_error If the value is absent. 
	 */
	FORCEINLINE T& GetOrThrow(const std::string errorMessage) const
	{
		if (ptr == nullptr)
			throw std::runtime_error(errorMessage);
		return *ptr;
	}

	/**
	 * If the contained reference is present, returns it.
	 *
	 * If absent, throws the exception created by the provided factory method.
	 *
	 * @throws std::exception If the value is absent. 
	 */
	template<typename _ExceptionFactory, std::enable_if_t<std::is_invocable_r_v<std::exception, _ExceptionFactory>, bool> = true>
	FORCEINLINE T& GetOrThrow(const _ExceptionFactory exceptionFactory) const
	{
		if (ptr == nullptr)
			throw exceptionFactory();
		return *ptr;
	}

	/**
	 * Returns the stored reference if present, else returns Default.
	 */
	FORCEINLINE T& GetOrDefault(T& Default) const noexcept
	{
		if (ptr == nullptr)
		{
			return Default;
		}
		return *ptr;
	}

	/**
	 * Returns the stored reference if present, else executes the provided function and returns it.
	 * @param computer A `T& (void)` function or lambda
	 */
	template<typename _Computer, std::enable_if_t<std::is_invocable_r_v<T&, _Computer>, int> = 0>
	FORCEINLINE T& GetOrCompute(_Computer computer)
	{
		if (IsPresent())
			return *ptr;
		
		return computer();
	}
	
	/**
	 * Get the stored reference as a pointer if present, else nullptr.
	 */
	FORCEINLINE T* GetPtrOrNull() const noexcept
	{
		return ptr;
	}

	FORCEINLINE T& GetUnchecked() const noexcept
	{
		return *ptr;
	}

	//endregion

	//region Actors/Mappers (Monad Functors)
	/**
	 * Execute the given lambda on the value if it is present, or does nothing if absent.
	 * @param action The action to be performed in the form of a `void(const T&)` function or lambda.
	 * @return This object.
	 */
	template<typename _Action, std::enable_if_t<std::is_invocable_v<_Action, const T&>, bool> = true>
	FORCEINLINE TOptRef IfPresent(_Action action) const
	{
		if (this->IsPresent())
		{
			action(*this->ptr);
		}
		return *this;
	}

	/**
	 * Executes the given action if the value is absent. Does nothing if the value is present.
	 * @param action The action function/lambda to be performed. Signature = `void()`
	 * @return This object.
	 */
	template<typename _Action, std::enable_if_t<std::is_invocable_v<_Action>, bool> = true>
	FORCEINLINE TOptRef IfAbsent(_Action action) const
	{
		if (this->IsAbsent())
		{
			action();
		}
		return *this;
	}

	/**
	 * Map the value to a new reference if present. Returns empty if absent.
	 *
	 * Should *not* be used with a newly generated value, only to map this reference to one stored somewhere else.
	 * To contain a value, see @link MapOwned@endlink.
	 * 
	 * @tparam R The new type.
	 * @param transformer The transformation function or lambda. Signature = `R&(const T&)` or `TRetainedRef<R>(const T&)`
	 * @return The new optional reference.
	 */
	template<typename R, typename _Mapper, std::enable_if_t<std::is_invocable_r_v<TRetainedRef<R>, _Mapper, const T&>, bool> = true>
	FORCEINLINE TOptRef<R> MapRef(_Mapper transformer) const
	{
		if (IsPresent())
			return TOptRef<R>(transformer(*ptr));

		return TOptRef<R>();
	}

	/**
	 * Map the value to the value of another optional reference if this value is present. Returns empty if absent.
	 *
	 * Used to connect another function that returns an optional with this one, so you don't get `TOptRef<TOptRef<Foo>>`.
	 * For example:
	 * @code
	 * class Foo {
	 *	 TOptRef<int> GetNumber();
	 * }
	 * 
	 * Foo foo;
	 * TOptRef<Foo> bar = TOptRef(foo);
	 * TOptRef<int> baz = bar.FlatMapRef<int>([](const Foo& it) -> TOptRef<int> { return it.GetNumber(); });
	 * assert(baz.IsPresent() == bar.IsPresent() && foo.GetNumber().IsPresent());
	 * assert(baz.GetOrThrow() == bar.GetOrThrow().GetNumber().GetOrThrow();
	 * @endcode
	 *
	 * Should *not* be used with a newly generated value, only to map this reference to one stored somewhere else.
	 * To contain a value, see @link MapOwned@endlink.
	 * 
	 * @tparam R The new type.
	 * @param transformer The transformation function or lambda. Signature = `R&(const T&)` or `TRetainedRef<R>(const T&)`
	 * @return The new optional reference.
	 */
	template<typename R, typename _Mapper, std::enable_if_t<std::is_invocable_r_v<TOptRef<R>, _Mapper, const T&>, bool> = true>
	FORCEINLINE TOptRef<R> FlatMapRef(_Mapper transformer) const
	{
		if (IsAbsent())
			return TOptRef<R>();
		
		return transformer(GetUnchecked());
	}

	/**
	 * If this value is absent or the predicate returns false, return an empty optional.
	 * @tparam Predicate A function or lambda that accepts `const T&` and returns either `true` to return the current instance or `false` to return an empty TOptRef.
	 * @return This instance if `shouldKeepValue` returns true or an empty TOptRef if `shouldKeepValue` returns false.
	 */
	template<typename Predicate, std::enable_if_t<std::is_invocable_r_v<bool, Predicate, const T&>, bool> = true>
	FORCEINLINE TOptRef Filter(Predicate shouldKeepValue) const
	{
		if (IsPresent() && shouldKeepValue(*ptr))
			return *this;
		return TOptRef();
	}

	/**
	 * Maps this reference to a new OWNED VALUE, which is STORED in the returned TOptional.
	 * Cannot return a reference.  To return a reference, use @link MapRef@endlink.
	 * 
	 * @tparam R The new type.
	 * @param transformer The function or lambda to generate the new value. Signature = `R(const T&)`
	 * @return A struct containing the newly-generated value, or empty if this object's stored value is absent.
	 */
	template<typename R, typename _Mapper, std::enable_if_t<std::is_invocable_r_v<R, _Mapper, const T&>, bool> = true>
	FORCEINLINE TOptional<R> MapOwned(_Mapper transformer) const
	{
		if (IsPresent())
			return TOptional<R>(transformer(*ptr));

		return TOptional<R>();
	}

	/**
	 * Maps this reference to a new OWNED VALUE, which is STORED in the returned TOptional. Used to connect another function that returns an optional with this one so you don't get `TOptional<TOptional<Foo>>`
	 * Cannot return a reference.  To return a reference, use @link MapRef@endlink.
	 * 
	 * @tparam R The new type.
	 * @param transformer The function or lambda to generate the new value. Signature = `TOptional<R>(const T&)`
	 * @return A struct containing the newly-generated value, or empty if this object's stored value or the transformer's return value is absent.
	 */
	template<typename R, typename _Mapper, std::enable_if_t<std::is_invocable_r_v<TOptional<R>, _Mapper, const T&>, bool> = true>
	FORCEINLINE TOptional<R> FlatMapOwned(_Mapper transformer) const
	{
		if (IsPresent())
			return transformer(*ptr);
		
		return TOptional<R>();
	}

	//endregion

	//region ToOwned
	/**
	 * Copy the value stored in this reference into one stored in the returned struct.
	 */
	FORCEINLINE TOptional<T> ToOwned() const noexcept
	{
		if (IsAbsent())
			return TOptional<T>();

		return TOptional<T>(*ptr);
	}

	/**
	 * Returns a copy of the stored reference if it is present, or else executes the provided function if the reference is absent.
	 *
	 * @param computer A function/lambda that accepts no arguments and returns an owned T instance.
	 */
	template<typename _Computer, std::enable_if_t<std::is_invocable_r_v<T, _Computer>, int> = 0>
	FORCEINLINE T ToOwnedOrCompute(_Computer computer)
	{
		if (IsPresent())
			return *ptr;
		
		return computer();
	}

	FORCEINLINE void ToOwned(TOptional<T>& Out) const noexcept
	{
		if (IsAbsent())
			Out = TOptional<T>();
		else
			Out = TOptional<T>(*ptr);
	}
	//endregion

	FORCEINLINE T& operator*()
	{
		return GetOrThrow();
	}

	FORCEINLINE T* operator->()
	{
		return &GetOrThrow();
	}

	//region Copy/Move
	TOptRef(const TOptRef& other)
		: ptr(other.ptr)
	{
	}

	TOptRef(TOptRef&& other) noexcept
		: ptr(other.ptr)
	{
	}

	TOptRef& operator=(const TOptRef& other)
	{
		if (this != &other)
			ptr = other.ptr;
		return *this;
	}

	TOptRef& operator=(TOptRef&& other) noexcept
	{
		if (this != &other)
			ptr = other.ptr;
		return *this;
	}

	//endregion

	//region Equality
	/**
	 * Checks object equality instead of pointer equality to keep the same contract as a standard reference.
	 */
	template<typename _Other, std::enable_if_t<std::is_convertible_v<T, _Other>, bool> = true>
	bool operator==(TOptRef<_Other> other) const noexcept
	{
		return IsPresent() == other.IsPresent()
			&& (ptr == other.ptr // should short-circuit the null case
				|| *ptr == *other.ptr); // should be null-safe
	}

	/**
	 * If they hold non-convertible types, it's false.
	 */
	template<typename _Other, std::enable_if_t<!std::is_convertible_v<T, _Other>, int> = 0>
	bool operator==(TOptRef<_Other> other) const noexcept
	{
		return false;
	}

	bool operator==(const T& other) const noexcept
	{
		return IsPresent() && *ptr == other;
	}

	bool operator==(T&& other) const noexcept
	{
		return IsPresent() && *ptr == other;
	}

	template<typename _Other, std::enable_if_t<std::is_assignable_v<T, _Other>, bool> = true>
	bool operator!=(TOptRef<_Other> other) const noexcept
	{
		return !(this == other);
	}

	bool operator!=(const T& other) const noexcept
	{
		return !(this == other);
	}

	bool operator!=(T&& other) const noexcept
	{
		return !(this == other);
	}


	//endregion
};

#pragma warning(pop)
