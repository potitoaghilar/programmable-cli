#ifndef CLI_PARSER_H
#define CLI_PARSER_H

#include "cli-action.h"
#include "cli.h"

class CLIParser {
    public:
        static std::vector<CLIAction> getActionsFromArgs(CLI*, std::vector<std::string>);
};

#endif
