#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include "cli-action.h"
#include "cli.h"
#include "console.h"
#include "process-manager.h"

using namespace std;

CLI::CLI() {
	// Help panel is a must have for every CLI
	this->registerAction(CLIAction(vector<string> {"-h", "--help"}, "Show this help panel."));
	// Interactive mode allow you to insert commands after entering the CLI
	this->registerAction(CLIAction("-i", "Enter interactive mode."));
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

	} catch (std::exception &e) {
		return false;
	}
	return true;
}

std::vector<CLIAction> CLI::getActions() {
	return this->actions;
}

int CLI::getActionsCount() {
	return this->getActions().size();
}

int CLI::execute(char *command[]) {

	// Check if actionName exists
	if(actionExists(CLIAction("",""))) { // TODO

		//CLIAction cli_action = CLI::getCLIAction(actionName);

		// TODO execute action

		return true;

	} else {

		Console::printError(strcat(command[1], ": action not found!\n\n"));
		return false;

	}
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
	throw std::runtime_error("");
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