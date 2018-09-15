#include "cli-parser.h"
#include "cli-action-simple.h"
#include "cli-action-param.h"
#include "cli-action-list.h"
#include "cli-no-action.h"
#include "cli.h"

using namespace std;

std::vector<CLIAction> CLIParser::getActionsFromArgs(CLI *cli, vector<string> commands) {

    vector<CLIAction> wantedActions;

    // Update CLIAction to set calledAction variable (the action that user want to perform)
    for(int i = 0; i < commands.size(); i++) {

        if(cli->actionExists(commands[i])) {
            CLIAction* action = cli->getCLIAction(commands[i]);
            action->setCalledAction(commands[i]);
            wantedActions.push_back(*action);

            // If this is a CLIActionParam get and save the param passed
            if(commands[i][0] == '-' && commands.size() - 1 > i) {
                CLIActionParam * child = static_cast <CLIActionParam*> (action);
                child->setContent("asdasd");
                //(static_cast <CLIActionParam*> (action))->setContent(commands[i + 1]);
                //cout << (static_cast <CLIActionParam*> (action))->getContent();
                i++;
            }

        } else {
            wantedActions.push_back(CLINoAction(commands[i]));
        }


    }

    return wantedActions;
}