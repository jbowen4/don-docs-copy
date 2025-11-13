

# File CollectionsUtils.spec.cpp

[**File List**](files.md) **>** [**DONToUnreal**](dir_7e70b7b4a1df651b2af4c8dca0b54b92.md) **>** [**Private**](dir_2c3ab2caebe6f83b4fac8c870e601c85.md) **>** [**Tests**](dir_f8e4318645a26694362a16079825ea46.md) **>** [**Util**](dir_59d96f77407b6d5ebafda3e626ba4b2b.md) **>** [**CollectionsUtils.spec.cpp**](_collections_utils_8spec_8cpp.md)

[Go to the documentation of this file](_collections_utils_8spec_8cpp.md)


```C++

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

```


