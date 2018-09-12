#include <iostream>
#include <vector>
#include "cli-action.h"

using namespace std;

CLIAction::CLIAction(string name, string description) {
	this->name.push_back(name);
	this->description = description;
}

CLIAction::CLIAction(vector<string> name, string description) {
	for(int i = 0; i < name.size(); i++) {
		this->name.push_back(name[i]);
	}
	this->description = description;
}

CLIAction::CLIAction(string name, string paramContent, string description) {
	this->name.push_back(name);
	this->description = description;
	this->paramContent = paramContent;
}

CLIAction::~CLIAction() {}

vector<string> CLIAction::getNames() {
	return name;
}

string CLIAction::getName(int i) {
	return name[i];
}

string CLIAction::namesToString() {
	string output = name[0];
	for(int i = 1; i < name.size(); i++) {
		output += ", " + name[i];
	}
	return output;
}

string CLIAction::getDescription()  {
	return description;
}