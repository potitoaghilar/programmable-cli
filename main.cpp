#include <iostream>
#include <vector>
#include <functional>
#include "cli-action-simple.h"
#include "cli-action-list.h"
#include "cli-action-param.h"
#include "cli.h"
#include "console.h"
#include "utils.h"

using namespace std;

int main(int argc, char* argv[]) {

	// Application name
	const string appName = "myApp";

	// Convert argv to a vector of strings
	vector<string> args = Utils::argvToArgs(argc, argv);

	// Header to show
	Console::print(appName + " - Command Line Interface (CLI)\n\n");

	/*#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)

	#else

	#endif*/

	// Main CLI object
	CLI cli;

	// The --help action and interactive mode are built-in.
	// To view help use ./CLI --help
	// To enter interactive mode use ./CLI -i
	// Chaining actions is also possible.

	// Simple action
	/*cli.registerAction(CLIActionSimple("action", "Custom simple action description.", []() {
		Console::print("Simple action test.\n\n");
	}));

	// Simple action with a parameter
	cli.registerAction(CLIActionParam("-a", "/some/path", "This action is called when a parameter -a is passed with content, in this case /some/path is a default value if no content is passed. A parametric action must start with at least a dash \"-\".", []() {

	    // Refer to the passed parameter with string "%param"
	    Console::print("Simple parametric action test. Content passed: %param\n\n");

	}));

	//These actions are in OR
	cli.registerAction(CLIActionList({"action1", "action2"}, "Action1 and action2 have the same effect.", []() {
		Console::print("Simple action list test.\n\n");
	}));*/


	// TODO - interactive mode


	if(argc == 1) {

		// Display help if no parameter is passed
		cli.help();

	} else {

		// Perform the wanted action
		if(!cli.execute(args)) {

			// Display help if action is not found
			cli.help();

			return 1;
		};

	}

	return 0;
}