

# File ObjectInfo.spec.cpp

[**File List**](files.md) **>** [**Data**](dir_53973666c712440193fe66b45b3a91b2.md) **>** [**ObjectInfo.spec.cpp**](_object_info_8spec_8cpp.md)

[Go to the documentation of this file](_object_info_8spec_8cpp.md)


```C++
#if WITH_DEV_AUTOMATION_TESTS

#include "Data/ObjectInfo.h"
#include "Misc/AutomationTest.h"
#include "Tests/TestUtils/TestUtils.h"

DEFINE_SPEC(FObjectInfoSpec, "Data.State.ObjectInfo", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter);

void FObjectInfoSpec::Define()
{
    Describe("Equality operator", [this]
    {
        It("Is equal when parents only have same name", [this]
        {
            FObjectInfo parent1(FName(TEXT("Foo")), true, TOptRef<const FObjectInfo>(), FVector(1), FQuat(2));
            FObjectInfo parent2(FName(TEXT("Foo")), true, TOptRef<const FObjectInfo>(), FVector(3), FQuat(5));

            RequireEqual("Parent names are equal", parent1.GetName(), parent2.GetName());

            FObjectInfo child1(FName(TEXT("Bar")), true, TOptRef<const FObjectInfo>(parent1), FVector(2), FQuat(3));
            FObjectInfo child2(FName(TEXT("Bar")), true, TOptRef<const FObjectInfo>(parent2), FVector(2), FQuat(3));

            TestEqual("Children are equal", child1, child2);
        });
        It("Is equal when both parents are absent", [this]
        {
            FObjectInfo parent1(FName(TEXT("Foo")), true, TOptRef<const FObjectInfo>(), FVector(1), FQuat(2));
            FObjectInfo parent2(FName(TEXT("Foo")), true, TOptRef<const FObjectInfo>(), FVector(1), FQuat(2));

            TestEqual("Considered equal", parent1, parent2);
        });
        It("Not equal when one parent is present and the other is not", [this]
        {
            FObjectInfo tested1(FName(TEXT("Foo")), true, TOptRef<const FObjectInfo>(), FVector(1), FQuat(2));
            FObjectInfo parent(FName(TEXT("Bar")), false, TOptRef<const FObjectInfo>(), FVector(4), FQuat(5));
            FObjectInfo tested2(FName(TEXT("Foo")), true, TOptRef<const FObjectInfo>(parent), FVector(1), FQuat(2));

            TestNotEqual("Not considered equal", tested1, tested2);
        });
        It("Not equal when parents have different names", [this]
        {
            FObjectInfo parent1(FName(TEXT("Foo")), true, TOptRef<const FObjectInfo>(), FVector(1), FQuat(2));
            FObjectInfo parent2(FName(TEXT("Baz")), true, TOptRef<const FObjectInfo>(), FVector(3), FQuat(5));

            FObjectInfo child1(FName(TEXT("Bar")), true, TOptRef<const FObjectInfo>(parent1), FVector(2), FQuat(3));
            FObjectInfo child2(FName(TEXT("Bar")), true, TOptRef<const FObjectInfo>(parent2), FVector(2), FQuat(3));

            TestNotEqual("Not considered equal", child1, child2);
        });
    });
}


#endif
```


