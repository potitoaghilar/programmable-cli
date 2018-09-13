#include "cli-parser.h"
#include "cli-no-action.h"

using namespace std;

std::vector<CLIAction> CLIParser::getActionsFromArgs(vector<CLIAction> actions, vector<string> commands) {

    vector<CLIAction> wantedActions;

    // Update CLIAction to set calledAction variable (the action that user want to perform)
    for(int i = 0; i < commands.size(); i++) {
        wantedActions.push_back(CLINoAction(commands[i]));
    }

    return wantedActions;
}