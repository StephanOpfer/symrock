#program alicaBackground.

%%%%% General relations between ALICA program elements

% A plan without parents is a root plan.
rootPlan(P) :- plan(P), not hasParentPlan(P, X) : plan(X), X!=P.

% Transitivity of hasParentPlan
hasParentPlan(Child, Parent) :- plan(Parent), plan(Child), hasState(Parent, S), hasPlan(S, Child).
hasParentPlan(Child, Parent) :- plan(Parent), plan(Child), planType(PT), hasState(Parent, S), hasPlanType(S, PT), hasRealisation(PT, Child).

% PreConditions and Run-time Conditions are subsets of Conditions.
condition(C) :- preCondition(C).
condition(C) :- runtimeCondition(C).

% Success and Failure States are subsets of Terminal States, which are subsets of States.
terminalState(S) :- successState(S).
terminalState(S) :- failureState(S).
state(S) :- terminalState(S).

% Inverse relations between predicates.
hasState(P,S) :- isStateOf(S,P).
isStateOf(S,P) :- hasState(P,S).
hasTransition(P,T) :- isTransitionOf(T,P).
hasInTransition(S,T) :- hasOutState(T,S).
hasOutState(T,S) :- hasInTransition(S,T).
hasOutTransition(S,T) :- hasInState(T,S).
hasInState(T,S) :- hasOutTransition(S,T).

% Reachability of states within plans
isReachableFrom(S,EP) :- hasInitialState(EP,S).
isReachableFrom(S2,S1) :- hasInState(T,S1), hasOutState(T,S2).
isReachableFrom(S3,S1) :- isReachableFrom(S2,S1), isReachableFrom(S3,S2).

% TODO: every plan has exactly one pre- and runtime condition, which is at least T

% TODO: every transition exactly one has a pre-condition, which is at least T

% TODO: every terminal state has exactly one post-condition, which is at least T

%pre- and run-time plan conditions
local(C) :- inRefPlan(C,P), hasPreCondition(P,C).

%%%%% Conditions for well-formed ALICA programs

% States belong to at most on plan.
brokenState(S) :- state(S), ParentPlansCnt = #count {P : isStateOf(S,P), plan(P)}, ParentPlansCnt > 1.

% No transition connects states in different plans.
brokenTransition(T) :- transition(T), state(SIN), state (SOut), plan(PIn) ,plan(POut), hasInState(T,SIn), hasOutState(T,SOut), isStateOf(SIn, PIn), isStateOf(SOut, POut), PIn != POut.

% Synchronisations only happen within a plan.
brokenSynchronisation(Synch) :- synchronisation(Synch), hasSynchedTransition(Synch, T1), hasSynchedTransition(Synch, T2), hasTransition(P2, T2), hasTransition(P1,T1), P1 != P2.

% Synchronsations must sync at least two transitions.
brokenSynchronisation(Synch) :- synchronisation(Synch), SynchedTransitionCnt = #count{T : hasSynchedTransition(Synch, T)}, SynchedTransitionCnt < 2.

% The failure and success states of a plan are disjoint (subsets of its states).
brokenTerminalState(S) :- successState(S), failureState(S).
brokenTerminalState(S) :- hasTerminalState(P, S), not hasState(P,S).

% Terminal states do not include sub-plans or behaviours
brokenTerminalState(S) :- terminalState(S), hasPlan(S,P).
brokenTerminalState(S) :- terminalState(S), hasPlanType(S,PT).
brokenTerminalState(S) :- terminalState(S), hasBehaviourConf(S,B).

% There is a postcondition associated with each success and failure state. 
brokenTerminalState(S) :- terminalState(S), PostConditionCnt = #count{PostC : hasPostCondition(S,PostC), postCondition(PostC)}, PostConditionCnt != 1.

% A task associated with a plan identifies an initial state within that plan
brokenPlanTaskPair(P, T) :- plan(P), task(T), hasTask(P,T), EntryPointCnt = #count{E : hasEntryPoint(P,T,E), entryPoint(E)}, EntryPointCnt != 1.
brokenEntryPoint(E) :- entryPoint(E), InitialStateCnt = #count{S : hasInitialState(E,S)}, InitialStateCnt > 1.

% Each state is reachable from exactly one entry point.
brokenState(S) :- state(S), ReachableEntryPointCnt = #count{EP: isReachableFrom(S,EP), entryPoint(EP)}, ReachableEntryPointCnt != 1.

%% CARDINALITIES

% All plan-task pairs have a valid cardinality interval associated. 
brokenEntryPoint(E) :- entryPoint(E), MinCardinalityCnt = #count{Min : hasMinCardinality(E,Min)}, MinCardinalityCnt != 1.
brokenEntryPoint(E) :- entryPoint(E), MaxCardinalityCnt = #count{Max : hasMaxCardinality(E,Max)}, MaxCardinalityCnt != 1.
brokenEntryPoint(E) :- entryPoint(E), hasMinCardinality(E, Min), hasMaxCardinality(E, Max), Min > Max.

% The sum of the minimum cardinalities of a child plan is larger than the maximum cardinality of the parents entry point

% - Check cardinalities for plans
brokenRunningPlan(ChildRP) :- hasEntryPoint(ParentPlan, ParentTask, ParentEntryPoint), isReachableFrom(ParentState, ParentEntrypoint), hasPlan(ParentState, ChildPlan), hasPlanInstance(ChildPlan, ChildRP), hasRunningPlan(ParentState, ChildRP),
	hasMaxCardinality(ParentEntrypoint, ParentMax),
	SumOfChildPlanMinCard = #sum { ChildMin : entryPoint(ChildEntryPoint), hasMinCardinality(ChildEntryPoint,ChildMin), hasEntryPoint(ChildPlan, ChildTask, ChildEntryPoint)},
	SumOfChildPlanMinCard > ParentMax.
	
% - Check cardinalities for plan types
brokenRunningPlan(ChildRP) :- hasEntryPoint(ParentPlan, ParentTask, ParentEntryPoint), isReachableFrom(ParentState, ParentEntrypoint), hasPlanType(ParentState, ParentPlanType), hasRealisation(ParentPlanType, ChildPlan), hasPlanInstance(ChildPlan, ChildRP), hasRunningPlan(ParentState, ChildRP),
	hasMaxCardinality(ParentEntrypoint, ParentMax),
	SumOfChildPlanMinCard = #sum { ChildMin : entryPoint(ChildEntryPoint), hasMinCardinality(ChildEntryPoint,ChildMin), hasEntryPoint(ChildPlan, ChildTask, ChildEntryPoint)},
	SumOfChildPlanMinCard > ParentMax.

%% CYCLES

% Cycles are not allowed in the plan hierarchy
cycleFree(P) :- plan(P), cycleFree(Parent):hasParentPlan(P,Parent).
cyclic(P) :- plan(P), not cycleFree(P).

% There is at most one root plan.
brokenPlan(P1) :- rootPlan(P1), rootPlan(P2), P1 != P2.

%% CONDITIONS & IN-PREDICATES

% Valid relations between the parameters of in predicates
brokenCondition(C) :- agent(A), plan(P), task(T), state(S), condition(C), inRefPlanState(C,P,S), not hasState(P,S).
brokenCondition(C) :- agent(A), plan(P), task(T), state(S), condition(C), inRefPlanTask(C,P,T), not hasTask(P,T).
brokenCondition(C) :- agent(A), plan(P), task(T), state(S), condition(C), inRefPlanTaskState(C,P,T,S), hasEntryPoint(P,T,E), not isReachableFrom(S,E).

% rules for non-local conditions
nonlocal(C) :- condition(C), not local(C).

%%
% Related to 
% perfectly (all agents are allocated) 
% complete (one plan for each plantype is executed) 
% recursive (recursivly down the plan hierarchy) 
% sound ()
% plans.

holds(C, RP) :- sound(P), plan(P), hasPlanInstance(P, RP), hasPreCondition(P,C).

holds(ChildC, ChildRP) :- hasPlanInstance(ChildP, ChildRP), hasPreCondition(ChildP,ChildC), runningPlan(ChildRP) : plan(P), hasParentPlan(ChildP, P), hasEntryPoint(P, T, EP), hasInitialState(EP, S), hasPlan(S, ChildP), hasRunningPlan(S, ChildRP), sound(P).

holds(C, RP) :- sound(P), plan(P), hasPlanInstance(P, RP), hasRuntimeCondition(P,C).

holds(ChildC, ChildRP) :- hasPlanInstance(ChildP, ChildRP), hasRuntimeCondition(ChildP,ChildC), runningPlan(ChildRP) : plan(P), hasParentPlan(ChildP, P), hasEntryPoint(P, T, EP), hasInitialState(EP, S), hasPlan(S, ChildP), hasRunningPlan(S, ChildRP), sound(P).

%%%%% General plan base axioms

%%%%% Conditions for well-formed plan base 
% These rules are relevant at run-time

% An agent can only occupy one state per plan 
brokenPlanBase(A) :- agent(A), runningPlan(RP), IsInStateCnt = #count{S : in(A,RP,T,S)}, IsInStateCnt > 1.

% An agent can only execute one plan per plantype
brokenPlanBase(A) :- agent(A), InPlanTypePlanCnt = #count{RP : in(A,RP,T,S), planType(PT), hasRealisation(PT,P), hasPlanInstance(P,RP), hasRunningPlan(ParentS, RP), hasRunningRealisation(PT, RP)}, InPlanTypePlanCnt > 1.

% The state occupied by an agent must be reachable (isReachableFrom) by its corresponding plan-task pair
brokenPlanBase(A) :- agent(A), hasTask(P,T), hasState(P,S), hasEntryPoint(P,T,E), hasPlanInstance(P,RP), in(A,RP,T,S), not isReachableFrom(S,E).









