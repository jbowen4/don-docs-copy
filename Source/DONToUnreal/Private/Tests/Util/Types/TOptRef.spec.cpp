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


