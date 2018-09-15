#ifndef CONSOLE_H
#define CONSOLE_H

class Console {
	public:
        static void print(std::string);
        static void printError(std::string);
        static void printAction(std::string, std::string, int);
        static void printHelp(std::vector<CLIAction>);
        static void printHeader(std::string, std::string = "Command Line Interface (CLI)");
    private:
        static int getMaxLengthFromActionsNames(std::vector<CLIAction>);

};

#endif