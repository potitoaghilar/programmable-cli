#include <iostream>
#include <vector>
#include <algorithm>
#include "cli-action.h"
#include "cli.h"
#include "console.h"

using namespace std;

void Console::print(string msg) {
	cout << msg;
}

void Console::printError(string msg) {
	cerr << msg;
}

void Console::printAction(string name, string description, int maxLength) {
	print("   " + name);
	print(string(maxLength - name.length(), ' '));
	print("\t\t" + description + "\n");
}

void Console::printHelp(vector<CLIAction> actions) {
	int maxLengthFromActionsNames = getMaxLengthFromActionsNames(actions);
	for(int i = 0; i < actions.size(); i++) {
		printAction(actions[i].namesToString(), actions[i].getDescription(), maxLengthFromActionsNames);
	}
	Console::print("\n");
}

int Console::getMaxLengthFromActionsNames(vector<CLIAction> actions) {
	vector<int> sizes;
	for(int i = 0; i < actions.size(); i++) {
		sizes.push_back(actions[i].namesToString().length());
	}
	return *max_element(sizes.begin(), sizes.end());
}