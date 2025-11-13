

# File TOptRef.spec.cpp

[**File List**](files.md) **>** [**DONToUnreal**](dir_7e70b7b4a1df651b2af4c8dca0b54b92.md) **>** [**Private**](dir_2c3ab2caebe6f83b4fac8c870e601c85.md) **>** [**Tests**](dir_f8e4318645a26694362a16079825ea46.md) **>** [**Util**](dir_59d96f77407b6d5ebafda3e626ba4b2b.md) **>** [**Types**](dir_83b80d16d9347cfd58393988c56fb5d0.md) **>** [**TOptRef.spec.cpp**](_t_opt_ref_8spec_8cpp.md)

[Go to the documentation of this file](_t_opt_ref_8spec_8cpp.md)


```C++
#if WITH_DEV_AUTOMATION_TESTS

#include "Misc/AutomationTest.h"
#include "Util/Types/TOptRef.h"

DEFINE_SPEC(TOptRefSpec, "Utils.Types.TOptRef", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter);


void TOptRefSpec::Define()
{
    Describe("Equality Operators", [this]
    {
        Describe("== TOptRef", [this]
        {
            Describe("Same type", [this]
            {
                It("is true when both are empty", [this]
                {
                    
                });
                It("is true when both are present and objects are the same", [this]
                {
                    
                });
                It("is false when this is empty", [this]
                {
                    
                });
                It("is false when other is empty", [this]
                {
                    
                });
                It("is false when both are present but objects are different", [this]
                {
                    
                });
            });
            Describe("Different types", [this]
            {
                It("is true when both are empty and objects are convertible", [this]
                {
                    
                });
                It("is false when both are empty and objects are not convertible", [this]
                {
                    
                });
                It("is true when both are present and objects are the same", [this]
                {
                    
                });
                It("is false when this is empty", [this]
                {
                    
                });
                It("is false when other is empty", [this]
                {
                    
                });
                It("is false when both are present but objects are different", [this]
                {
                    
                });
            });
        });
    });
}


#endif


```


