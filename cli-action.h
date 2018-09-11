
class CLIAction {
	public:
		CLIAction(std::string, std::string);
		//~CLIAction();
		std::string getName();
		std::string getDescription();

	private:
		std::string name;
		std::string description;
};