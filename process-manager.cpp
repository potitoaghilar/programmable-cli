#include <iostream>
#include <cstdlib>
#include "process-manager.h"

using namespace std;

void ProcessManager::startProcess(string command) {
	system(command.c_str());
}