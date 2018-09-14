#ifndef CLI_ACTION_H
#define CLI_ACTION_H

#include <iostream>
#include <vector>
#include <functional>

class CLI;

class CLIAction {
	public:
        ~CLIAction();
		std::vector<std::string> getNames();
		std::string getName(int i = 0);
		std::string namesToString();
		std::string getDescription();
        void setCalledAction(std::string);
        std::string getCalledAction();
        void execute();
        bool isNoAction;

    protected:
        CLIAction(std::vector<std::string>, std::string, std::function<void (CLI* cli)>);
        CLIAction(); // This constructor is for CLINoAction type
		std::vector<std::string> names;
		std::string description;
		std::string calledAction;
        std::function<void (CLI*)> function;

};

#endif