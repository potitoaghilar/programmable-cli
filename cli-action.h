#ifndef CLI_ACTION_H
#define CLI_ACTION_H

class CLIAction {
	public:
		CLIAction(std::string, std::string);
		CLIAction(std::vector<std::string>, std::string);
		CLIAction(std::string, std::string, std::string);
		~CLIAction();
		std::vector<std::string> getNames();
		std::string getName(int i = 0);
		std::string namesToString();
		std::string getDescription();

	private:
		std::vector<std::string> name;
		std::string description;
		std::string paramContent;
};

#endif