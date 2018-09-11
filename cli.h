
class CLI {
	public:
		CLI();
		//~CLI();
		void registerAction(CLIAction);
		std::vector<CLIAction> getActions();
		int getActionsCount();
		int execute(std::string actionName);
		void help();

		// CLI actions - write here your custom actions methods
		void customAction();

	private:
		std::vector<CLIAction> actions;
		CLIAction getCLIAction(int);
		CLIAction getCLIAction(std::string);

};