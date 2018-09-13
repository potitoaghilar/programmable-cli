#include <iostream>
#include <vector>
#include <map>
#include "cli-action-simple.h"
#include "cli-action-list.h"
#include "cli-action-param.h"
#include "cli.h"
#include "console.h"

using namespace std;

int main(int argc, char* argv[]) {

	// Application name
	const string appName = "myApp";

	// Header to show
	Console::print(appName + " - Command Line Interface (CLI)\n\n");

	// Main CLI object
	CLI cli;

	// The --help action and interactive mode are built-in.
	// To view help use ./CLI --help
	// To enter interactive mode use ./CLI -i

	cli.registerAction(CLIActionSimple("action", "Custom simple action description.")); // Simple action
	cli.registerAction(CLIActionParam("-a", "/some/path", "This action is called when a parameter -a is passed with content.")); // Simple action with a parameter
	cli.registerAction(CLIActionList({"action1", "action2"}, "Action1 and action2 have the same effect.")); //These actions are in OR

	if(argc == 1) {

		// Display help if no parameter is passed
		cli.help();

	} else {

		// Perform the wanted action
		if(!cli.execute(argv)) {

			// Display help if action is not found
			cli.help();

			return 1;
		};

	}

	return 0;
}