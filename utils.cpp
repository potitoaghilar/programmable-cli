#include <vector>
#include "utils.h"

using namespace std;

std::vector<string> Utils::argvToArgs(int argc, char *command[]) {

    vector<string> args;

    // Avoid first argument... the CLI program invocation itself
    for(int i = 1; i < argc; i++) {
        args.push_back(command[i]);
    }

    return args;

}