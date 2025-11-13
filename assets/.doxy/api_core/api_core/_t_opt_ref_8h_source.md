

# File TOptRef.h

[**File List**](files.md) **>** [**DONToUnreal**](dir_7e70b7b4a1df651b2af4c8dca0b54b92.md) **>** [**Public**](dir_c336ec6675be099178e02bcdcfb186ce.md) **>** [**Util**](dir_91e92cab0a0b5df2370f6d3ddd515cf6.md) **>** [**Types**](dir_0b672cd9ffed74d397856df63ef6d83a.md) **>** [**TOptRef.h**](_t_opt_ref_8h.md)

[Go to the documentation of this file](_t_opt_ref_8h.md)


```C++
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#pragma warning(push)
#pragma warning( disable : 5030 )// disable "unrecognized attribute" warning for [[jetbrains::pass_by_value]]

#include "CoreMinimal.h"

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
    FORCEINLINE T& GetOrThrow() const
    {
        return GetOrThrow("TOptRef: Attempted to dereference null.");
    }

    FORCEINLINE T& GetOrThrow(const std::string errorMessage) const
    {
        if (ptr == nullptr)
            throw std::runtime_error(errorMessage);
        return *ptr;
    }

    template<typename _ExceptionFactory, std::enable_if_t<std::is_invocable_r_v<std::exception, _ExceptionFactory>, bool> = true>
    FORCEINLINE T& GetOrThrow(const _ExceptionFactory exceptionFactory) const
    {
        if (ptr == nullptr)
            throw exceptionFactory();
        return *ptr;
    }

    FORCEINLINE T& GetOrDefault(T& Default) const noexcept
    {
        if (ptr == nullptr)
        {
            return Default;
        }
        return *ptr;
    }

    template<typename _Computer, std::enable_if_t<std::is_invocable_r_v<T&, _Computer>, int> = 0>
    FORCEINLINE T& GetOrCompute(_Computer computer)
    {
        if (IsPresent())
            return *ptr;
        
        return computer();
    }
    
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
    template<typename _Action, std::enable_if_t<std::is_invocable_v<_Action, const T&>, bool> = true>
    FORCEINLINE TOptRef IfPresent(_Action action) const
    {
        if (this->IsPresent())
        {
            action(*this->ptr);
        }
        return *this;
    }

    template<typename _Action, std::enable_if_t<std::is_invocable_v<_Action>, bool> = true>
    FORCEINLINE TOptRef IfAbsent(_Action action) const
    {
        if (this->IsAbsent())
        {
            action();
        }
        return *this;
    }

    template<typename R, typename _Mapper, std::enable_if_t<std::is_invocable_r_v<TRetainedRef<R>, _Mapper, const T&>, bool> = true>
    FORCEINLINE TOptRef<R> MapRef(_Mapper transformer) const
    {
        if (IsPresent())
            return TOptRef<R>(transformer(*ptr));

        return TOptRef<R>();
    }

    template<typename R, typename _Mapper, std::enable_if_t<std::is_invocable_r_v<TOptRef<R>, _Mapper, const T&>, bool> = true>
    FORCEINLINE TOptRef<R> FlatMapRef(_Mapper transformer) const
    {
        if (IsAbsent())
            return TOptRef<R>();
        
        return transformer(GetUnchecked());
    }

    template<typename Predicate, std::enable_if_t<std::is_invocable_r_v<bool, Predicate, const T&>, bool> = true>
    FORCEINLINE TOptRef Filter(Predicate shouldKeepValue) const
    {
        if (IsPresent() && shouldKeepValue(*ptr))
            return *this;
        return TOptRef();
    }

    template<typename R, typename _Mapper, std::enable_if_t<std::is_invocable_r_v<R, _Mapper, const T&>, bool> = true>
    FORCEINLINE TOptional<R> MapOwned(_Mapper transformer) const
    {
        if (IsPresent())
            return TOptional<R>(transformer(*ptr));

        return TOptional<R>();
    }

    template<typename R, typename _Mapper, std::enable_if_t<std::is_invocable_r_v<TOptional<R>, _Mapper, const T&>, bool> = true>
    FORCEINLINE TOptional<R> FlatMapOwned(_Mapper transformer) const
    {
        if (IsPresent())
            return transformer(*ptr);
        
        return TOptional<R>();
    }

    //endregion

    //region ToOwned
    FORCEINLINE TOptional<T> ToOwned() const noexcept
    {
        if (IsAbsent())
            return TOptional<T>();

        return TOptional<T>(*ptr);
    }

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
    template<typename _Other, std::enable_if_t<std::is_convertible_v<T, _Other>, bool> = true>
    bool operator==(TOptRef<_Other> other) const noexcept
    {
        return IsPresent() == other.IsPresent()
            && (ptr == other.ptr // should short-circuit the null case
                || *ptr == *other.ptr); // should be null-safe
    }

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
```


