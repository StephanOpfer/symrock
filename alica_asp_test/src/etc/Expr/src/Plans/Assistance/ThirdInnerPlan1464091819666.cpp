#include "Plans/Assistance/ThirdInnerPlan1464091819666.h"
using namespace alica;
/*PROTECTED REGION ID(eph1464091819666) ENABLED START*/ // Add additional using directives here
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
// Plan:ThirdInnerPlan

// Check of RuntimeCondition - (Name): NewRuntimeCondition, (ConditionString): agent(A), in(A,p1464096415101, tsk1225112227903, S)., (Comment) :

/*
 * Available Vars:
 */
bool RunTimeCondition1464096415101::evaluate(shared_ptr<RunningPlan> rp)
{
    /*PROTECTED REGION ID(1464096415101) ENABLED START*/
    return true;
    /*PROTECTED REGION END*/
}

/* generated comment

 Task: DefaultTask  -> EntryPoint-ID: 1464091833200

 */
shared_ptr<UtilityFunction> UtilityFunction1464091819666::getUtilityFunction(Plan* plan)
{
    /*PROTECTED REGION ID(1464091819666) ENABLED START*/

    shared_ptr<UtilityFunction> defaultFunction = make_shared<DefaultUtilityFunction>(plan);
    return defaultFunction;

    /*PROTECTED REGION END*/
}

// State: NewState in Plan: ThirdInnerPlan

} // namespace alicaAutogenerated
