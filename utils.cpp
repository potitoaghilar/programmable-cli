#include <vector>
#include "utils.h"

using namespace std;

std::vector<string> Utils::argvToArgs(int argc, char *command[]) {
    vector<string> args;
    for(int i = 0; i < argc; i++) {
        args.push_back(command[i]);
    }
    return args;
}