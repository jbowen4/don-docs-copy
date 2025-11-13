// ReSharper disable CppDoxygenUndocumentedParameter

#pragma once
#if WITH_DEV_AUTOMATION_TESTS

#include "Misc/AutomationTest.h"


/// Return false if this is false
#define retIfFalse(func) if (!func) return false

/**
 * Extra testing functions.
 *
 * NOTE: For some bizarre reason, the linker refuses to link to these when they aren't inlined.
 * Since they're absolutely massive, use DECLARE_TEST_UTILS() in your spec to declare them in place.
 *		Plus you'll be able to use "this->TestEqual(...)" instead of "TestUtils::TestEqual(this, ...)"
 */
class TestUtils
{
public:
	template<typename T, typename Stringifier, std::enable_if_t<std::is_invocable_r_v<FString, Stringifier, const T&>, int> = 0>
	FORCEINLINE static FString ListToString(const TArray<T>& list, Stringifier stringifier)
	{
		FStringBuilderBase sb;
		sb.AppendChar('[');
		for (auto& auto_ : list)
		{
			sb.Append(stringifier(auto_)).AppendChar(',');
		}
		sb.RemoveSuffix(1);
		return sb.ToString();
	}

	template<typename K, typename V>
	static bool TestEqual(FAutomationSpecBase* spec, const TMap<K, V>& actual, const TMap<K, V>& expected)
	{
		TArray<K> expectedKeys;
		expected.GenerateKeyArray(expectedKeys);
		TArray<K> actualKeys;
		actual.GenerateKeyArray(actualKeys);
		retIfFalse(TestContentsEqual(spec, actualKeys, expectedKeys));

		for (auto& key : expectedKeys)
		{
			retIfFalse(spec->TestEqual<V>("Values are the same", actual[key], expected[key]));
		}
		return true;
	}

	/**
	 * Tests that each element of array1 is equal to the corresponding element of array2, using their equality operator.
	 */
	template<typename T>
	static bool TestContentsEqual(FAutomationSpecBase* spec, const TArray<T>& actual, const TArray<T>& expected)
	{
		if (!spec->TestEqual("Arrays are the same length", actual.Num(), expected.Num()))
			return false;
		bool wasGood = true;

		for (auto len = actual.Num(), i = 0; i < len; ++i)
		{
			if (!spec->TestEqual<T>(*FString::Printf(TEXT("Index %d"), i), actual[i], expected[i]))
				wasGood = false;
		}
		return wasGood;
	}

	template<typename T>
	static bool TestContentsEqual_Unordered(FAutomationSpecBase* spec, const TArray<T>& actual, const TArray<T>& expected)
	{
		if (!spec->TestEqual("Array length", actual.Num(), expected.Num()))
			return false;
		TMap<T, TArray<int32>> expectedItemIndices;
		TMap<T, TArray<int32>> actualItemIndices;

		for (int32 i = 0, len = expected.Num(); i < len; ++i)
		{
			expectedItemIndices.FindOrAdd(expected[i], TArray<int32>()).Add(i);
		}
		for (int32 i = 0, len = actual.Num(); i < len; ++i)
		{
			actualItemIndices.FindOrAdd(actual[i], TArray<int32>()).Add(i);
		}

		bool hadError = false;
		for (TPair<T, TArray<int32>>& expected_item_val : expectedItemIndices)
		{
			T& key = expected_item_val.Key;
			TArray<int32>* indicesInActual = actualItemIndices.Find(key);
			TArray<int32>& expectedIndices = expected_item_val.Value;
			if (indicesInActual == nullptr || indicesInActual->Num() != expectedIndices.Num())
			{
				FString expectedListString = ListToString<int32>(expectedIndices, [](const int32& it) { return FString::FromInt(it); });
				FString actualListString;
				if (indicesInActual == nullptr)
				{
					actualListString = "";
				}
				else
				{
					actualListString = ListToString(*indicesInActual, [](const int32& it) { return FString::FromInt(it); });
				}
				const FString testStr = FString::Printf(L"Expected %d items (indices=%ls), actual %d items (indices=%ls)", expectedIndices.Num(), *expectedListString, indicesInActual == nullptr ? 0 : indicesInActual->Num(), *actualListString);
				spec->AddError(testStr);
				hadError = true;
			}
		}

		// check the stuff in actual that was not in expected:
		TArray<T> expectedUniqueItems;
		expectedItemIndices.GetKeys(expectedUniqueItems);

		for (auto& actual_item_index : actualItemIndices)
		{
			if (expectedUniqueItems.Contains(actual_item_index.Key))
				continue;
			auto testStr2 = ListToString<int32>(actual_item_index.Value, [](auto& it) { return FString::FromInt(it); });
			const FString testStr = FString::Printf(L"Actual had %d items (indices=%ls) not in expected.", actual_item_index.Value.Num(), *testStr2);
			spec->AddError(testStr);
			hadError = true;
		}

		return !hadError;
	}
};

#undef retIfFalse

/// Declare the functions non-inlined in a spec
#define DECLARE_TEST_UTILS\
	template<typename T> bool TestContentsEqual(const TArray<T>& actual, const TArray<T>& expected) { return TestUtils::TestContentsEqual(this, actual, expected); }\
	template<typename T> bool TestContentsEqual_Unordered(const TArray<T>& actual, const TArray<T>& expected) { return TestUtils::TestContentsEqual_Unordered(this, actual, expected); } \
	template<typename K, typename V> bool TestMapsEqual(const TMap<K, V>& actual, const TMap<K, V>& expected) { return TestUtils::TestEqual(this, actual, expected); }


#define RequireTrue(desc, expr) if (!TestTrue(desc, expr)) return
#define RequireEqual(desc, item1, item2) if (!TestEqual(desc, item1, item2)) return

#endif
