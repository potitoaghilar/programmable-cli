#ifndef CLI_H
#define CLI_H

class CLI {
	public:
		CLI();
		~CLI();
		void registerAction(CLIAction);
		bool actionExists(CLIAction);
		bool actionExists(std::string);
        CLIAction* getCLIAction(int);
        CLIAction* getCLIAction(std::string);
		std::vector<CLIAction> getActions();
		int getActionsCount();
		int execute(std::vector<std::string>);
        void help();

	private:
		std::vector<CLIAction> actions;
        void help(CLI* cli);

};

#endif