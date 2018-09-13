#include <iostream>
#include <vector>
#include "cli-action-list.h"

using namespace std;

CLIActionList::CLIActionList(vector<string> names, string description) : CLIAction(names, description) {};

CLIActionList::~CLIActionList() {}