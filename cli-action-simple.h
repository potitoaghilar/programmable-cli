#ifndef CLI_ACTION_SIMPLE_H
#define CLI_ACTION_SIMPLE_H

#include "cli-action.h"

class CLIActionSimple : public CLIAction {
	public:
		CLIActionSimple(std::string, std::string = "", std::function<void ()> = []() {});
		~CLIActionSimple();
};

#endif