#ifndef CLI_ACTION_PARAM_H
#define CLI_ACTION_PARAM_H

#include "cli-action.h"

class CLIActionParam : public CLIAction {
	public:
		CLIActionParam(std::string, std::string, std::string = "", std::function<void ()> = []() {});
		~CLIActionParam();
		void setContent(std::string);
		std::string getContent();
	private:
		std::string content;
};

#endif