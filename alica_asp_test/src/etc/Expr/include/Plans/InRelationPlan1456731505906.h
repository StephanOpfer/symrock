#ifndef InRelationPlan_H_
#define InRelationPlan_H_

#include "DomainCondition.h"
#include "engine/BasicUtilityFunction.h"
#include "engine/DefaultUtilityFunction.h"
#include "engine/UtilityFunction.h"
/*PROTECTED REGION ID(incl1456731505906) ENABLED START*/
// Add inlcudes here
/*PROTECTED REGION END*/
using namespace alica;

namespace alicaAutogenerated
{
/*PROTECTED REGION ID(meth1456731505906) ENABLED START*/
// Add other things here
/*PROTECTED REGION END*/
class UtilityFunction1456731505906 : public BasicUtilityFunction
{
    shared_ptr<UtilityFunction> getUtilityFunction(Plan* plan);
};

class PreCondition1456731822708 : public DomainCondition
{
    bool evaluate(shared_ptr<RunningPlan> rp);
};

} // namespace alicaAutogenerated

#endif
