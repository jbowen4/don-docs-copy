#pragma once

#ifndef GETTER
	/**
	 * Create a getter for a field that passes by const reference with the name `Get<FieldName>()`.
	 *
	 * Assumes no exceptions can be thrown by the method.
	 *
	 * Example: `GETTER(int, Foo)` becomes `const int& GetFoo() const noexcept { return Foo; }`
	 */
	#define GETTER(fieldType, fieldName) \
		USE_RET FORCEINLINE const fieldType& Get##fieldName() const noexcept { return fieldName; }
#endif

#ifndef USE_RET
	/**
	 * Marks that the return value of this function should always be used in some way, and it is an error to not use it.
	 *
	 * It could be because this function's sole purpose is to return a value with no side effects, or because this function returns an error type that must be accounted for.
	 */
	#define USE_RET [[nodiscard]]
#endif
