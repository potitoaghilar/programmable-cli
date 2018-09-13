#include <iostream>
#include <vector>
#include "cli-action.h"
#include "cli-action-param.h"

using namespace std;

/*CLIAction::CLIAction(string name, string description) {
	this->name.push_back(name);
	this->description = description;
}*/

/*CLIAction::CLIAction(CLIActionParam actionParam, string description) {
	this->name.push_back(actionParam.getParam());
	this->description = description;
	this->paramContent = actionParam.getContent();
}*/

CLIAction::CLIAction(vector<string> names, string description) {
	for(int i = 0; i < names.size(); i++) {
		this->names.push_back(names[i]);
	}
	this->description = description;
}

CLIAction::~CLIAction() {}

vector<string> CLIAction::getNames() {
	return names;
}

string CLIAction::getName(int i) {
	return names[i];
}

string CLIAction::namesToString() {
	string output = names[0];
	for(int i = 1; i < names.size(); i++) {
		output += ", " + names[i];
	}
	return output;
}

string CLIAction::getDescription()  {
	return description;
}