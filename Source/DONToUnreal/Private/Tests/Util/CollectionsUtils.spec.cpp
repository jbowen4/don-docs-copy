
#if WITH_DEV_AUTOMATION_TESTS
#include "Misc/AutomationTest.h"
#include "Util/CollectionsUtils.h"

using namespace CollectionsUtils;

DEFINE_SPEC(CollectionsUtilsSpec, "Utils.Functions.CollectionsUtils", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

void CollectionsUtilsSpec::Define()
{
	Describe("List", [this]
	{
		Describe("RemoveFirstMatchingAndGet", [this]
		{
			It("Acts when value is present", [this]
		   {
			   std::list list = {0, 1, 2, 3, 4, 5, 6};
			   auto oldsize = list.size();
			   auto got = List::RemoveFirstMatchingAndGet<int>(list, [](auto i) { return i == 1; });
			   TestTrue("Returned has value", got.IsSet());
			   TestEqual("Returned correct value", got.GetValue(), 1);
			   TestEqual("Removed any value from the list", list.size(), oldsize - 1);
			   TestTrue("Removed correct value from list", !std::any_of(list.begin(), list.end(), [](auto i) { return i == 1; }));
		   });
		   It("Does nothing when value is absent", [this]
		   {
			   std::list list = {0, 1, 2, 3, 4, 5, 6};
			   auto oldsize = list.size();
			   auto got = List::RemoveFirstMatchingAndGet<int>(list, [](auto i) { return i == 7; });
			   TestTrue("Returned is empty", !got.IsSet());
			   TestEqual("List is unchanged", list.size(), oldsize);
		   });
		});
	});

	Describe("Stack", [this]
	{
		Describe("PopHeadAndGet", [this]{
			It("Returns value when stack has items", [this]
		   {
			   std::stack<int> stack;
			   stack.push(1);
			   stack.push(2);
			   stack.push(3);
			   auto ret = Stack::PopHeadAndGet(stack);
			   TestTrue("Returned a value", ret.IsSet());
			   TestEqual("Returns correct value", ret.GetValue(), 3);
		   });
		   It("Does nothing when stack is empty", [this]
		   {
			   std::stack<int> stack;
			   auto ret = Stack::PopHeadAndGet(stack);
			   TestTrue("Returned nothing", !ret.IsSet());
		   });
		});
	});

	Describe("Map", [this]
	{
		Describe("ComputeIfAbsent", [this]
		{
			It("Calls the function exactly once when the value is absent", [this]
			{
				
			});
			It("Does not call the function when the value is present", [this]
			{
				
			});
		});
	});
}


#endif

