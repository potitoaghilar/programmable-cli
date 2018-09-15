#ifndef UTILS_H
#define UTILS_H

#include <string>

class Utils {
    public:
        static std::vector<std::string> argvToArgs(int argc, char *commands[]);
};

#endif
