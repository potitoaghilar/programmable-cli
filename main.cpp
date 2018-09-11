#include <iostream>
#include <vector>
#include "cli-action.h"
#include "cli.h"
#include "console.h"

using namespace std;

int main(int argc, char* argv[]) {

	// Application name
	const string appName = "myApp";

	// Header to show
	Console::print(appName + " - Command Line Interface (CLI)\n\n");

	// CLI
	CLI cli;
	cli.registerAction(CLIAction("-h", "Show this help panel."));
	cli.registerAction(CLIAction("--help", "Show this help panel."));
	cli.registerAction(CLIAction("--action", "Custom action description"));

	if(argc == 1) {

		// Display help if no parameter is passed
		cli.help();

	} else {

		// Perform the wanted action
		if(!cli.execute(argv[1])) {

			// Display help if action is not found
			cli.help();

			return 1;
		};

	}

	return 0;
}