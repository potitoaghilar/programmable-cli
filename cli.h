#ifndef CLI_H
#define CLI_H

class CLI {
	public:
		CLI();
		~CLI();
		void registerAction(CLIAction);
		bool actionExists(CLIAction);
		bool actionExists(std::string);
		std::vector<CLIAction> getActions();
		int getActionsCount();
		int execute(char *command[]);
		void help();

		// CLI actions - write here your custom actions methods
		void customAction();

	private:
		std::vector<CLIAction> actions;
		CLIAction getCLIAction(int);
		CLIAction getCLIAction(std::string);

};

#endif