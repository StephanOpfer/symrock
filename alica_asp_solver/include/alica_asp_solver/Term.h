/*
 * Term.h
 *
 *  Created on: Jul 13, 2016
 *      Author: Stefan Jakob
 */

#ifndef INCLUDE_ALICA_ASP_SOLVER_TERM_H_
#define INCLUDE_ALICA_ASP_SOLVER_TERM_H_

#include <engine/constraintmodul/SolverTerm.h>
#include <string>
#include <memory>
#include <vector>

using namespace std;

namespace alica
{
	namespace reasoner
	{

		class Term : public enable_shared_from_this<Term>, public alica::SolverTerm
		{
		public:
			Term(int lifeTime = 1);
			virtual ~Term();
			bool setRule(string rule);
			string getRuleHead();
			string getRuleBody();
			string getBackGroundFileName();
			void setBackgroundFileName(string backgroundFile);
			int getLifeTime();
			string getRule();
			void addFact(string fact);
			vector<string> getFacts();

		private :
			string rule;
			string head;
			string body;
			string backgroundFile;
			int lifeTime;
			vector<string> facts;
		};

	} /* namespace reasoner */
} /* namespace alica */

#endif /* INCLUDE_ALICA_ASP_SOLVER_TERM_H_ */