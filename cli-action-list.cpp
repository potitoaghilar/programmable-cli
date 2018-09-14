#include <iostream>
#include <vector>
#include "cli-action-list.h"

using namespace std;

CLIActionList::CLIActionList(vector<string> names, string description, std::function<void (CLI*)> function) : CLIAction(names, description, function) {};

CLIActionList::~CLIActionList() {}