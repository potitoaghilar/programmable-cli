#include "environment.h"

bool Environment::isWin() {

    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        return true;
    #else
        return false;
    #endif

}

bool Environment::isUnix() {
    return !isWin();
}