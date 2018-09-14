#ifndef CLI_ACTION_LIST_H
#define CLI_ACTION_LIST_H

#include "cli-action.h"

class CLIActionList : public CLIAction {
	public:
		CLIActionList(std::vector<std::string>, std::string = "", std::function<void ()> = []() {});
		~CLIActionList();
};

#endif