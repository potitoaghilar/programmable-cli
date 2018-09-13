#include <iostream>
#include <vector>
#include "cli-action-param.h"

using namespace std;

CLIActionParam::CLIActionParam(string param, string defaultContent, string description) : CLIAction({param}, description) {
	this->content = content;
}

CLIActionParam::~CLIActionParam() {}

string CLIActionParam::getDefaultContent()  {
	return content;
}