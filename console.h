
class Console {
	public:
        static void print(std::string);
        static void printError(std::string);
        static void printAction(std::string, std::string, int);
        static void printHelp(std::vector<CLIAction>);
    private:
        static int getMaxLengthFromActionsNames(std::vector<CLIAction>);

};