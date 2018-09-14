#include <iostream>
#include <vector>
#include "cli-action-param.h"

#include "cli-action.h"

using namespace std;

CLIActionParam::CLIActionParam(string param, string defaultContent, string description, std::function<void (CLI*)> function) : CLIAction({param}, description, function) {
	this->content = content;

	// Auto add dash as first char
	if(param[0] != '-') {
		// Add a dash as first char
		this->names[0] = "-" + this->names[0];
	}

}

CLIActionParam::~CLIActionParam() {}

string CLIActionParam::getDefaultContent()  {
	return content;
}