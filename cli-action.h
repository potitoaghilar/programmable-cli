#ifndef CLI_ACTION_H
#define CLI_ACTION_H

#include <iostream>
#include <vector>

class CLIAction {
	public:
        ~CLIAction();
		std::vector<std::string> getNames();
		std::string getName(int i = 0);
		std::string namesToString();
		std::string getDescription();
		std::string getCalledAction();

    protected:
        CLIAction(std::vector<std::string>, std::string);
        CLIAction(); // This constructor is for CLINoAction type
		std::vector<std::string> names;
		std::string description;
		std::string calledAction;
};

#endif