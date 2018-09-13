#ifndef CLI_PARSER_H
#define CLI_PARSER_H

#include "cli-action.h"

class CLIParser {
    public:
        static std::vector<CLIAction> getActionsFromArgs(std::vector<CLIAction>, std::vector<std::string>);
};

#endif
