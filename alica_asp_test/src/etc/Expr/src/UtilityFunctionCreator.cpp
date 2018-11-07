#include "UtilityFunctionCreator.h"
#include <iostream>

#include "Plans/UpperPlanInPlantype1462793904808.h"

#include "Plans/NonLocalInRelation1456730912737.h"

#include "Plans/CyclePlanA1453033636578.h"

#include "Plans/ReferencedPlan1456731591075.h"

#include "Plans/InRelationPlan1456731505906.h"

#include "Plans/ReusePlanFromPlantypeWithoutCycle1464355916688.h"

#include "Plans/CyclePlanC1453033651069.h"

#include "Plans/HierarchicalInconsistentCardinalities1453033407259.h"

#include "Plans/ReusePlanWithoutCycle1455093185652.h"

#include "Plans/InconsistentCardinalities1462886292442.h"

#include "Plans/IndirectReusePlanInPlantype1462793790517.h"

#include "Plans/BrokenCardPlan1462879159773.h"

#include "Plans/CyclePlanB1453033643893.h"

#include "Plans/Min3AgentPlan1453033506291.h"

#include "Plans/Assistance/SecondInnerPlan1464027620934.h"

#include "Plans/UnconnectedSynchronisations1455035766972.h"

#include "Plans/TaskTwicePlan1453033761283.h"

#include "Plans/Assistance/ThirdInnerPlan1464091819666.h"

#include "Plans/Assistance/CarryBookMaster1462889118325.h"

#include "Plans/Assistance/CarryBook1462889426092.h"

#include "Plans/LocalInconsistentCardinalities1453033347284.h"

#include "Plans/SingleUnconnectedState1452783421979.h"

#include "Plans/UnconnectedStateMachine1452783558494.h"

#include "Plans/LowerPlanInPlantype1462793912377.h"

#include "Plans/Assistance/InnerPlan1464027589619.h"

using namespace std;
using namespace alicaAutogenerated;
namespace alica
{

UtilityFunctionCreator::~UtilityFunctionCreator() {}

UtilityFunctionCreator::UtilityFunctionCreator() {}

shared_ptr<BasicUtilityFunction> UtilityFunctionCreator::createUtility(long utilityfunctionConfId)
{
    switch (utilityfunctionConfId) {

    case 1462793904808:
        return make_shared<UtilityFunction1462793904808>();
        break;

    case 1456730912737:
        return make_shared<UtilityFunction1456730912737>();
        break;

    case 1453033636578:
        return make_shared<UtilityFunction1453033636578>();
        break;

    case 1456731591075:
        return make_shared<UtilityFunction1456731591075>();
        break;

    case 1456731505906:
        return make_shared<UtilityFunction1456731505906>();
        break;

    case 1464355916688:
        return make_shared<UtilityFunction1464355916688>();
        break;

    case 1453033651069:
        return make_shared<UtilityFunction1453033651069>();
        break;

    case 1453033407259:
        return make_shared<UtilityFunction1453033407259>();
        break;

    case 1455093185652:
        return make_shared<UtilityFunction1455093185652>();
        break;

    case 1462886292442:
        return make_shared<UtilityFunction1462886292442>();
        break;

    case 1462793790517:
        return make_shared<UtilityFunction1462793790517>();
        break;

    case 1462879159773:
        return make_shared<UtilityFunction1462879159773>();
        break;

    case 1453033643893:
        return make_shared<UtilityFunction1453033643893>();
        break;

    case 1453033506291:
        return make_shared<UtilityFunction1453033506291>();
        break;

    case 1464027620934:
        return make_shared<UtilityFunction1464027620934>();
        break;

    case 1455035766972:
        return make_shared<UtilityFunction1455035766972>();
        break;

    case 1453033761283:
        return make_shared<UtilityFunction1453033761283>();
        break;

    case 1464091819666:
        return make_shared<UtilityFunction1464091819666>();
        break;

    case 1462889118325:
        return make_shared<UtilityFunction1462889118325>();
        break;

    case 1462889426092:
        return make_shared<UtilityFunction1462889426092>();
        break;

    case 1453033347284:
        return make_shared<UtilityFunction1453033347284>();
        break;

    case 1452783421979:
        return make_shared<UtilityFunction1452783421979>();
        break;

    case 1452783558494:
        return make_shared<UtilityFunction1452783558494>();
        break;

    case 1462793912377:
        return make_shared<UtilityFunction1462793912377>();
        break;

    case 1464027589619:
        return make_shared<UtilityFunction1464027589619>();
        break;

    default:
        cerr << "UtilityFunctionCreator: Unknown utility requested: " << utilityfunctionConfId << endl;
        throw new exception();
        break;
    }
}

} // namespace alica
