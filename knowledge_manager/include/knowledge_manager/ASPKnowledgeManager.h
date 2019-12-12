#pragma once
#include <reasoner/asp/Solver.h>
#include <mutex>
#include <vector>

namespace knowledge_manager
{
class ASPKnowledgeManager
{
public:
    ASPKnowledgeManager();
    virtual ~ASPKnowledgeManager();
    virtual void setSolver(reasoner::asp::Solver *solver);
    std::vector<std::string> solve(std::string queryRule, std::string programSection);
    int addInformation(std::vector<std::string>& information, int lifetime = -1);
    void revoke(int queryID);

    //TODO remove later;
    void add(char const* name, Clingo::StringSpan const& params, char const* part);
    void ground(Clingo::PartSpan vec, Clingo::GroundCallback callBack);
    bool solve();
    Clingo::Symbol parseValue(std::string const& str);

    reasoner::asp::Solver *getSolver();

private:
    ::reasoner::asp::Solver* solver;
    std::vector<std::string> currentSolution;
    std::mutex mtx;
    std::vector<int> currentQueryIDs;
};

} /* namespace knowledge_manager */