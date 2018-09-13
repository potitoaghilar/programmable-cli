#ifndef CLINOACTION_H
#define CLINOACTION_H

#include "cli-action.h"

class CLINoAction : public CLIAction {
    public:
        CLINoAction(std::string calledAction);
        ~CLINoAction();
};

#endif