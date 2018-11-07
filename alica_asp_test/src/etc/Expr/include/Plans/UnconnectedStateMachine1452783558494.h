#ifndef UnconnectedStateMachine_H_
#define UnconnectedStateMachine_H_

#include "DomainCondition.h"
#include "engine/BasicUtilityFunction.h"
#include "engine/DefaultUtilityFunction.h"
#include "engine/UtilityFunction.h"
/*PROTECTED REGION ID(incl1452783558494) ENABLED START*/
// Add inlcudes here
/*PROTECTED REGION END*/
using namespace alica;

namespace alicaAutogenerated
{
/*PROTECTED REGION ID(meth1452783558494) ENABLED START*/
// Add other things here
/*PROTECTED REGION END*/
class UtilityFunction1452783558494 : public BasicUtilityFunction
{
    shared_ptr<UtilityFunction> getUtilityFunction(Plan* plan);
};

class TransitionCondition1452783594228 : public DomainCondition
{
    bool evaluate(shared_ptr<RunningPlan> rp);
};

class TransitionCondition1452783604156 : public DomainCondition
{
    bool evaluate(shared_ptr<RunningPlan> rp);
};

class TransitionCondition1452783597877 : public DomainCondition
{
    bool evaluate(shared_ptr<RunningPlan> rp);
};

class TransitionCondition1452783600822 : public DomainCondition
{
    bool evaluate(shared_ptr<RunningPlan> rp);
};

class TransitionCondition1452783605843 : public DomainCondition
{
    bool evaluate(shared_ptr<RunningPlan> rp);
};

class TransitionCondition1452783595930 : public DomainCondition
{
    bool evaluate(shared_ptr<RunningPlan> rp);
};

} // namespace alicaAutogenerated

#endif
