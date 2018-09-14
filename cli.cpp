#include <iostream>
#include <vector>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <stdexcept>
#include <typeinfo>
#include "cli-action-simple.h"
#include "cli-action-list.h"
#include "cli-action-param.h"
#include "cli.h"
#include "console.h"
#include "process-manager.h"
#include "cli-parser.h"

using namespace std;

CLI::CLI() {
	// Help panel is a must have for every CLI
	this->registerAction(CLIActionList({"-h", "--help"}, "Show this help panel."));
	// Interactive mode allow you to insert commands after entering the CLI
	this->registerAction(CLIActionSimple("-i", "Enter interactive mode."));
}

CLI::~CLI() {}

void CLI::registerAction(CLIAction action) {

	// Check if actionName already exists
	if(actionExists(action)) {
		Console::printError("Conflict detected with another action name while trying to add \"" + action.namesToString() + "\". Closing...\n");
		exit(1);
	} else {
		this->actions.push_back(action);
	}

}

bool CLI::actionExists(CLIAction action) {
	try {

		for(int i = 0; i < action.getNames().size(); i++) {
			CLI::getCLIAction(action.getName(i));
		}

	} catch (std::exception e) {
		return false;
	}
	return true;
}

bool CLI::actionExists(string actionName) {
	return actionExists(CLIActionSimple(actionName));
}

std::vector<CLIAction> CLI::getActions() {
	return this->actions;
}

int CLI::getActionsCount() {
	return this->getActions().size();
}

int CLI::execute(std::vector<std::string> commands) {

	// Parse commands to actions
	vector<CLIAction> wantedActions = CLIParser::getActionsFromArgs(this->getActions(), commands);

	for(int i = 0; i < wantedActions.size(); i++) {

	    // What is the number appeared on first char?
		if(((string)typeid(wantedActions[i]).name()).find("CLINoAction") != std::string::npos) {

			Console::print(wantedActions[i].getCalledAction() + " action is called\n");
			// TODO - call lambda function for this action

		} else {

		    // Exit if one action in the chain is not found
			Console::printError(wantedActions[i].getCalledAction() + ": action not found!\n\n");
			return false;

		}

		// Check if action name exists
		/*if(actionExists(actions[i])) { // TODO <-- implement this check inside CLIParser
		} else {}*/

	}

	return true;

}

CLIAction CLI::getCLIAction(int i) {
	return this->actions[i];
}

CLIAction CLI::getCLIAction(string actionName) {
	for(int i = 0; i < this->getActionsCount(); i++) {
		for(int o = 0; o < this->actions[i].getNames().size(); o++) {
			if(this->actions[i].getName(o) == actionName) {
				return this->actions[i];
			}
		}
	}
	throw std::runtime_error("Action not found!");
}

// CLI actions methods

void CLI::help() {
	Console::printHelp(this->getActions());
}

void CLI::customAction() {
    // TODO - implement windows and unix differences
	#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
		ProcessManager::startProcess("<custom windows cmd script>");
	#else
		ProcessManager::startProcess("<custom unix bash script>");
	#endif
}