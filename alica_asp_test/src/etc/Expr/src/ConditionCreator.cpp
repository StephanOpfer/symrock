#include "ConditionCreator.h"

#include  "Plans/UpperPlanInPlantype1462793904808.h"

#include  "Plans/Min3AgentPlan1453033506291.h"

#include  "Plans/NonLocalInRelation1456730912737.h"

#include  "Plans/UnconnectedSynchronisations1455035766972.h"

#include  "Plans/TaskTwicePlan1453033761283.h"

#include  "Plans/CyclePlanA1453033636578.h"

#include  "Plans/HouseKeepingDomain/CarryBook1462889426092.h"

#include  "Plans/ReferencedPlan1456731591075.h"

#include  "Plans/LocalInconsistentCardinalities1453033347284.h"

#include  "Plans/InRelationPlan1456731505906.h"

#include  "Plans/CyclePlanC1453033651069.h"

#include  "Plans/SingleUnconnectedState1452783421979.h"

#include  "Plans/HouseKeepingDomain/CarryBookMaster1462889118325.h"

#include  "Plans/HierarchicalInconsistentCardinalities1453033407259.h"

#include  "Plans/ReusePlanWithoutCycle1455093185652.h"

#include  "Plans/InconsistentCardinalities1462886292442.h"

#include  "Plans/UnconnectedStateMachine1452783558494.h"

#include  "Plans/IndirectReusePlanInPlantype1462793790517.h"

#include  "Plans/BrokenCardPlan1462879159773.h"

#include  "Plans/LowerPlanInPlantype1462793912377.h"

#include  "Plans/CyclePlanB1453033643893.h"

using namespace alicaAutogenerated;
namespace alica
{

    ConditionCreator::ConditionCreator()
    {
    }
    ConditionCreator::~ConditionCreator()
    {
    }

    shared_ptr<BasicCondition> ConditionCreator::createConditions(long conditionConfId)
    {
        switch (conditionConfId)
        {

            case 1455035817820:

                return make_shared<TransitionCondition1455035817820>();

                break;

            case 1455035907819:

                return make_shared<TransitionCondition1455035907819>();

                break;

            case 1462889683880:

                return make_shared<PreCondition1462889683880>();

                break;

            case 1456731822708:

                return make_shared<PreCondition1456731822708>();

                break;

            case 1452783594228:

                return make_shared<TransitionCondition1452783594228>();

                break;

            case 1452783595930:

                return make_shared<TransitionCondition1452783595930>();

                break;

            case 1452783597877:

                return make_shared<TransitionCondition1452783597877>();

                break;

            case 1452783600822:

                return make_shared<TransitionCondition1452783600822>();

                break;

            case 1452783604156:

                return make_shared<TransitionCondition1452783604156>();

                break;

            case 1452783605843:

                return make_shared<TransitionCondition1452783605843>();

                break;

            default:
                cerr << "ConditionCreator: Unknown condition id requested: " << conditionConfId << endl;
                throw new exception();
                break;
        }
    }
}
