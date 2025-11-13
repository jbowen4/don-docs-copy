#if WITH_DEV_AUTOMATION_TESTS

#include "Misc/AutomationTest.h"
#include "Tests/TestUtils/TestUtils.h"

BEGIN_DEFINE_SPEC(TestUtilsSpec, "Test.TestUtils", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter);
	DECLARE_TEST_UTILS
END_DEFINE_SPEC(TestUtilsSpec)

void TestUtilsSpec::Define()
{
	Describe("TestContentsEqual", [this]
	{
		It("Returns true when contents are equal in same order", [this]
		{
			TArray<int> arr1 = {0, 1, 2, 3, 4};
			TArray<int> arr2 = {0, 1, 2, 3, 4};
			TestTrue("Returns true", TestContentsEqual(arr1, arr2));
		});
		It("Returns false when arrays have different lengths", [this]
		{
			TArray arr1 = {0, 1, 2, 3, 4, 5};
			TArray arr2 = {0, 1, 2, 3, 4};
			AddExpectedError("Arrays are the same length", EAutomationExpectedErrorFlags::Contains, 1);
			TestFalse("Returns false", TestContentsEqual(arr1, arr2));
		});
		It("Returns false when arrays have same elements in different order", [this]
		{
			TArray arr1 = {0, 1, 4, 3, 2};
			TArray arr2 = {0, 1, 2, 3, 4};
			AddExpectedError("The two values are not equal", EAutomationExpectedErrorFlags::Contains, 2);
			TestFalse("Returns false", TestContentsEqual(arr1, arr2));
		});
		It("Returns false when arrays have different elements", [this]
		{
			TArray arr1 = {1, 2, 3, 4};
			TArray arr2 = {5, 6, 7, 8};
			AddExpectedError("The two values are not equal", EAutomationExpectedErrorFlags::Contains, 4);
			TestFalse("Returns false", TestContentsEqual(arr1, arr2));
		});
		It("Returns true when both arrays are empty", [this]
		{
			TArray<int> arr1 = {};
			TArray<int> arr2 = {};
			TestTrue("Returns true", TestContentsEqual(arr1, arr2));
		});
	});

	Describe("TestUtils::TestContentsEqual_Unordered", [this]
	{
		It("Returns true when contents are equal in same order", [this]
		{
			TArray<int> arr1 = {0, 1, 2, 3, 4};
			TArray<int> arr2 = {0, 1, 2, 3, 4};
			TestTrue("Returns true", TestContentsEqual_Unordered(arr1, arr2));
		});
		It("Returns true when arrays have same elements in different order", [this]
		{
			TArray arr1 = {0, 1, 4, 3, 2};
			TArray arr2 = {0, 1, 2, 3, 4};
			TestTrue("Returns true", TestContentsEqual_Unordered(arr1, arr2));
		});
		It("Returns true when contents are equal in same order with duplicates", [this]
		{
			TArray<int> arr1 = {0, 1, 2, 3, 4, 4, 2};
			TArray<int> arr2 = {0, 1, 2, 3, 4, 4, 2};
			TestTrue("Returns true", TestContentsEqual_Unordered(arr1, arr2));
		});
		It("Returns true when arrays have same elements in different order with duplicates", [this]
		{
			TArray arr1 = {0, 1, 4, 1, 3, 2, 4};
			TArray arr2 = {0, 4, 1, 2, 3, 1, 4};
			TestTrue("Returns true", TestContentsEqual_Unordered(arr1, arr2));
		});
		It("Returns false when arrays have different lengths", [this]
		{
			TArray arr1 = {0, 1, 2, 3, 4, 5};
			TArray arr2 = {0, 1, 2, 3, 4};
			AddExpectedError("Array length", EAutomationExpectedErrorFlags::Contains, 1);
			TestFalse("Returns false", TestContentsEqual_Unordered(arr1, arr2));
		});
		It("Returns false when arrays have different elements", [this]
		{
			TArray arr1 = {1, 2, 3, 4};
			TArray arr2 = {5, 6, 7, 8};
			AddExpectedError("Expected \\d+ items", EAutomationExpectedErrorFlags::Contains, 4);
			AddExpectedError("not in expected", EAutomationExpectedErrorFlags::Contains, 4);
			TestFalse("Returns false", TestContentsEqual_Unordered(arr1, arr2));
		});
		It("Returns true when both arrays are empty", [this]
		{
			TArray<int> arr1 = {};
			TArray<int> arr2 = {};
			TestTrue("Returns true", TestContentsEqual_Unordered(arr1, arr2));
		});
	});
}


#endif
