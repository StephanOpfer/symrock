/*
 * SolveCommand.h
 *
 *  Created on: Jan 20, 2017
 *      Author: stefan
 */

#ifndef SRC_COMMANDS_SOLVECOMMAND_H_
#define SRC_COMMANDS_SOLVECOMMAND_H_

#include <commands/Command.h>
#include <memory>
#include <clingo/clingocontrol.hh>

#include <QJsonObject>

namespace kbcr
{

	class KnowledgebaseCreator;
	/**
	 * Class inheriting from Command interface used to call the solvers solve method
	 */
	class SolveCommand : public Command, public std::enable_shared_from_this<SolveCommand>
	{
		Q_OBJECT
	public:
		SolveCommand(KnowledgebaseCreator* gui);
		virtual ~SolveCommand();

		void execute();
		void undo();

		QJsonObject toJSON();
		/**
		 * Get models returned by solve call
		 */
		std::vector<Gringo::SymVec> getCurrentModels();
		/**
		 * Return solver result
		 */
		bool isSatisfiable();

		KnowledgebaseCreator* gui;

	private:
		bool satisfiable;
		std::vector<Gringo::SymVec> currentModels;
		/**
		 * Print models unsorted
		 */
		void printModels();
		/**
		 * Print models sorted
		 */
		void printSortedModels();
	};

} /* namespace kbcr */

#endif /* SRC_COMMANDS_SOLVECOMMAND_H_ */