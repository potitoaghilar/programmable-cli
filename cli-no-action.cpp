#include "cli-no-action.h"

using namespace std;

CLINoAction::CLINoAction(string calledAction) {
    this->calledAction = calledAction;
}

CLINoAction::~CLINoAction() {}