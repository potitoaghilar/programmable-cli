#include <iostream>
#include <vector>
#include "cli-action-simple.h"

using namespace std;

CLIActionSimple::CLIActionSimple(string name, string description) : CLIAction({name}, description) {};

CLIActionSimple::~CLIActionSimple() {}