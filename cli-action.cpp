#include <iostream>
#include <vector>
#include "cli-action.h"

using namespace std;

CLIAction::CLIAction(string name, string description) {
	this->name = name;
	this->description = description;
}

string CLIAction::getName() {
	return name;
}

string CLIAction::getDescription()  {
	return description;
}