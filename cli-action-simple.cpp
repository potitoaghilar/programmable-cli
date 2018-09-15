#include <iostream>
#include <vector>
#include "cli-action-simple.h"

using namespace std;

CLIActionSimple::CLIActionSimple(string name, string description, std::function<void ()> function) : CLIAction({name}, description, function) {};

CLIActionSimple::~CLIActionSimple() {}