#ifndef CLI_ACTION_H
#define CLI_ACTION_H

class CLIAction {
	public:
        ~CLIAction();
		std::vector<std::string> getNames();
		std::string getName(int i = 0);
		std::string namesToString();
		std::string getDescription();

    protected:
        CLIAction(std::vector<std::string>, std::string);
		std::vector<std::string> names;
		std::string description;
};

#endif