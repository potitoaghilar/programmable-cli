#include <iostream>
#include <vector>
#include "cli-action.h"
#include "cli.h"
#include "console.h"
#include "process-manager.h"

using namespace std;

CLI::CLI() {}

void CLI::registerAction(CLIAction action) {
	this->actions.push_back(action);
}

std::vector<CLIAction> CLI::getActions() {
	return this->actions;
}

int CLI::getActionsCount() {
	return this->getActions().size();
}

int CLI::execute(std::string actionName) {

	try {

		CLIAction cli_action = CLI::getCLIAction(actionName);

		// TODO execute action

		return true;

	} catch (const char* msg) {

		Console::printError(msg);
		return false;

	}
}

CLIAction CLI::getCLIAction(int i) {
	return this->actions[i];
}

CLIAction CLI::getCLIAction(string actionName) {
	for(int i = 0; i < this->getActionsCount(); i++) {
		if(this->actions[i].getName() == actionName) {
			return this->actions[i];
		}
	}
	throw "Action not found!";
}

// CLI actions methods

void CLI::help() {
	Console::printHelp(this->getActions());
}

void CLI::customAction() {
	#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
		ProcessManager::startProcess("<custom windows cmd script>");
	#else
		ProcessManager::startProcess("<custom unix bash script>");
	#endif
}