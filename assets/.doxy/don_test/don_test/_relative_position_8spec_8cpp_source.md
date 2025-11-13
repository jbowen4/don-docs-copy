

# File RelativePosition.spec.cpp

[**File List**](files.md) **>** [**Data**](dir_53973666c712440193fe66b45b3a91b2.md) **>** [**RelativePosition.spec.cpp**](_relative_position_8spec_8cpp.md)

[Go to the documentation of this file](_relative_position_8spec_8cpp.md)


```C++


#if WITH_DEV_AUTOMATION_TESTS

#include "Data/RelativePosition.h"
#include "Misc/AutomationTest.h"

DEFINE_SPEC(FRelativePositionSpec, "Data.State.RelativePosition", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter);

using RPos = FRelativePosition;
using Vec = FVector;
using Quat = FQuat;
using Opt = TOptRef<const FRelativePosition>;

inline FVector randVector()
{
    return FVector(rand(), rand(), rand());
}

void FRelativePositionSpec::Define()
{
    Describe("Constructors", [this]
    {
        It("Test ORIGIN invariants", [this]
        {
            auto x = RPos::ORIGIN;
            TestEqual("Is at 0,0,0", x.GetRelativePos(), FVector(0,0,0));
            TestEqual("GetNestIndex() = 0", x.GetNestIndex(), 0);
            FVector out(0); x.GetAbsolutePosition(out);
            TestEqual("GetAbsolutePosition = (0,0,0)", out, FVector(0,0,0));
            FQuat out2(0); x.GetAbsoluteOrientation(out2);
            TestEqual("GetAbsoluteOrientation = (0,0,0,0)", out2, FQuat(0,0,0,0));
        });
        
        Describe("No parent = ORIGIN", [this]{
            It("Should parent the origin when given a null parent", [this]
            {
                FRelativePosition pos(nullptr, FVector(), FQuat());
                TestTrue("Parent == ORIGIN", pos.GetParent() == FRelativePosition::ORIGIN);
            });
            It("Should parent the origin when given an empty optional", [this]
            {
                FRelativePosition pos = FRelativePosition(Opt(), FVector(), FQuat());
                TestTrue("Parent == ORIGIN", pos.GetParent() == FRelativePosition::ORIGIN);
            });
        });
        Describe("Links to parent properly and takes nest index + 1", [this]
        {
            It("Works with FRelativePosition* constructor", [this]
            {
                FRelativePosition parent(&FRelativePosition::ORIGIN, FVector(), FQuat());
                TestTrue("Parent nest index == 1", parent.GetNestIndex() == 1);
                FRelativePosition child(&parent, FVector(1,2,3), FQuat(4,5,6,7));
                TestTrue("Childs parent is set", child.GetParent() == parent);
                TestTrue("Childs nest index == 2", child.GetNestIndex() == 2);
            });
            It("Works with TOptional constructor", [this]
            {
                FRelativePosition parent = FRelativePosition(Opt(FRelativePosition::ORIGIN), FVector(), FQuat());
                TestTrue("Parent nest index == 1", parent.GetNestIndex() == 1);
                FRelativePosition child(Opt(parent), FVector(1,2,3), FQuat(4,5,6,7));
                TestTrue("Childs parent is set", child.GetParent() == parent);
                TestTrue("Childs nest index == 2", child.GetNestIndex() == 2);
            });
        });
    });

    
    Describe("GetAbsolutePosition", [this]
    {
        It("Returns own position when parent is ORIGIN", [this]
        {
            RPos pos(nullptr, randVector(), Quat(4,5,6,7));
            Vec out(0); pos.GetAbsolutePosition(out);
            TestEqual("Output = pos.GetRelativePos()", out, pos.GetRelativePos());
        });
        It("Cascades with longer chains", [this]
        {
            RPos p1(nullptr, randVector(), Quat(4,5,6,7));
            RPos p2(&p1, randVector(), Quat(6,7,8,9));
            RPos p3(&p2, randVector(), Quat(1,4,5,6));
            Vec out(0);
            p3.GetAbsolutePosition(out);
            TestEqual("Output is equal to p3 + p2 + p1 + ORIGIN", out, RPos::ORIGIN.GetRelativePos() + p1.GetRelativePos() + p2.GetRelativePos() + p3.GetRelativePos());
        });
    });

    Describe("static GetPositionsRelativeToCommonParent", [this]
    {
        Describe("Normal Use", [this] {
            // note: apostrophes break tests
           It("Returns each ones original position when both already share a parent", [this]
           {
               RPos parent(nullptr, randVector(), Quat());
               RPos p1(&parent, randVector(), Quat());
               RPos p2(&parent, randVector(), Quat());
               Vec out1, out2;
               TestEqual("Operation successful", FRelativePosition::ErrorCode::OK, RPos::GetPositionsRelativeToCommonParent(p1, p2, out1, out2));
               TestEqual("out1 == p1.GetRelativePos()", out1, p1.GetRelativePos());
               TestEqual("out2 == p2.GetRelativePos()", out2, p2.GetRelativePos());
           });
           Describe("On same branch", [this]
           {
               It("Is correct when first param is more nested", [this]
               {
                   RPos rootParent(nullptr, Vec(1,0,0), Quat());
                        RPos branchParent(&rootParent, Vec(1<<2,0,0), Quat());
                            RPos p1(&branchParent, Vec(1<<4,0,0), Quat());
                        RPos p2(&rootParent, Vec(1<<6,0,0), Quat());
                   Vec out1(0), out2(0);
                   TestEqual("Operation successful", RPos::GetPositionsRelativeToCommonParent(p1, p2, out1, out2), FRelativePosition::ErrorCode::OK);
                   TestEqual("Less-nested position is unchanged", out2, p2.GetRelativePos());
                   TestEqual("More-nested position is relativized", out1, p1.GetRelativePos() + branchParent.GetRelativePos());
               });
               It("Is correct when second param is more nested", [this]
               {
                   RPos rootParent(nullptr, Vec(1,0,0), Quat());
                   RPos branchParent(&rootParent, Vec(1<<2,0,0), Quat());
                   RPos p1(&rootParent, Vec(1<<4,0,0), Quat());
                   RPos p2(&branchParent, Vec(1<<6,0,0), Quat());
                   Vec out1(0), out2(0);
                   TestEqual("Operation successful", RPos::GetPositionsRelativeToCommonParent(p1, p2, out1, out2), FRelativePosition::ErrorCode::OK);
                   TestEqual("Less-nested position is unchanged", out1, p1.GetRelativePos());
                   TestEqual("More-nested position is relativized", out2, p2.GetRelativePos() + branchParent.GetRelativePos());
               });
           });
        
           Describe("On different branches", [this]
           {
               It("Both equally nested", [this]
               {
                   RPos rootParent(nullptr, randVector(), Quat());
                   RPos branch1Parent(&rootParent, randVector(), Quat());
                   RPos branch2Parent(&rootParent, randVector(), Quat());
                   RPos p1(&branch1Parent, randVector(), Quat());
                   RPos p2(&branch2Parent, randVector(), Quat());
                   Vec out1(0), out2(0);
                   TestEqual("Operation successful", RPos::GetPositionsRelativeToCommonParent(p1, p2, out1, out2), FRelativePosition::ErrorCode::OK);
                   TestEqual("First position", out1, p1.GetRelativePos() + branch1Parent.GetRelativePos());
                   TestEqual("Second position", out2, p2.GetRelativePos() + branch2Parent.GetRelativePos());
               });
               It("arg1 is more nested", [this]
               {
                   RPos rootParent(nullptr, randVector(), Quat());
                        RPos branch1Parent(&rootParent, randVector(), Quat());
                            RPos less(&branch1Parent, randVector(), Quat());
                        RPos branch2Parent(&rootParent, randVector(), Quat());
                            RPos branch2_2(&branch2Parent, randVector(), Quat());
                                RPos more(&branch2_2, randVector(), Quat());
                   Vec outmore(0), outless(0);
                   TestEqual("Operation successful", RPos::GetPositionsRelativeToCommonParent(more, less, outmore, outless), FRelativePosition::ErrorCode::OK);
                   TestEqual("Less-nested position", outless, less.GetRelativePos() + branch1Parent.GetRelativePos());
                   TestEqual("More-nested position", outmore, more.GetRelativePos() + branch2_2.GetRelativePos() + branch2Parent.GetRelativePos());
               });
               It("arg2 is more nested", [this]
               {
                   RPos rootParent(nullptr, Vec(1,0,0), Quat());
                   RPos branch1Parent(&rootParent, Vec(2,0,0), Quat());
                   RPos branch2Parent(&rootParent, Vec(4,0,0), Quat());
                   RPos less(&branch1Parent, Vec(8,0,0), Quat());
                   RPos branch2_2(&branch2Parent, Vec(16,0,0), Quat());
                   RPos more(&branch2_2, Vec(32,0,0), Quat());
                   Vec outmore(0), outless(0);
                   TestEqual("Operation successful", RPos::GetPositionsRelativeToCommonParent(less, more, outless, outmore), FRelativePosition::ErrorCode::OK);
                   TestEqual("Less-nested position", outless, less.GetRelativePos() + branch1Parent.GetRelativePos());
                   TestEqual("More-nested position", outmore, more.GetRelativePos() + branch2_2.GetRelativePos() + branch2Parent.GetRelativePos());
               });
           });
        });
        Describe("Error cases", [this]
        {
            // TODO
        });
    });

    Describe("GetPositionRelativeTo", [this]
    {
        It("Returns own position when Other is ORIGIN", [this]
        {
            RPos p1(nullptr, randVector(), Quat());
            Vec out(0);
            TestEqual("Operation successful", p1.GetPositionRelativeTo(RPos::ORIGIN, out), FRelativePosition::ErrorCode::OK);
            TestEqual("output == own position", out, p1.GetRelativePos());
        });
        It("Works when other is its parent", [this]
        {
            RPos parent(nullptr, randVector(), Quat());
            RPos child(&parent, randVector(), Quat());
            Vec out(0);
            TestEqual("Operation successful", child.GetPositionRelativeTo(parent, out), FRelativePosition::ErrorCode::OK);
            TestEqual("Relative to parent", out, child.GetRelativePos());
        });
        It("Works when other is its child", [this]
        {
            RPos parent(nullptr, randVector(), Quat());
            RPos child(&parent, randVector(), Quat());
            Vec out(0);
            TestEqual("Operation successful", parent.GetPositionRelativeTo(child, out), FRelativePosition::ErrorCode::OK);
            TestEqual("Relative to child", out, -child.GetRelativePos());
        });
        It("Works when other is on different branch", [this]
        {
            RPos root(nullptr, randVector(), Quat());
            RPos branch1(&root, randVector(), Quat());
            RPos branch2(&root, randVector(), Quat());
            RPos p1(&branch1, randVector(), Quat());
            RPos p2(&branch2, randVector(), Quat());
            Vec out(0);
            TestEqual("Operation successful", p1.GetPositionRelativeTo(p2, out), FRelativePosition::ErrorCode::OK);
            TestEqual("Relative position across branches", out, p1.GetRelativePos() + branch1.GetRelativePos() - p2.GetRelativePos() - branch2.GetRelativePos());
        });
    });
    Describe("DistanceTo", [this]
    {
        It("Both have same parent", [this]
        {
            RPos p1(nullptr, randVector(), FQuat());
            RPos p2(nullptr, randVector(), FQuat());
            TestEqual("Correct output", p1.DistanceTo(p2), FVector::Distance(p1.GetRelativePos(), p2.GetRelativePos()));
        });
        It("Both equally nested on different branches", [this]
        {
            //TODO
        });
        It("One more nested than the other on different branches", [this]
        {
            //TODO
        });
        It("One is the parent of the other", [this]
        {
            //TODO
        });
        It("One is the grandparent of the other", [this]
        {
            //TODO
        });
    });
}


#endif






```


