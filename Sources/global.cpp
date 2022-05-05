#include <iostream>
#include "../Sources/Headers/global.h"

/*	Define 'global' class functions	*/
void global::SetValue(std::string _value, std::string _variable) {
	if (_variable == "gID") this->gID = _value;
	else if (_variable == "gUser") this->gUser = _value;
	else if (_variable == "gEmail")  this->gEmail = _value;
	else { std::cout << "Invalid variable!" << std::endl; exit(1); }
}

std::string global::GetValue(std::string _variable) {
	if (_variable == "gID") return this->gID;
	else if (_variable == "gUser") return this->gUser;
	else if (_variable == "gEmail") return this->gEmail;
	else { std::cout << "Invalid variable!" << std::endl; exit(1); }
}

void global::Clear() {
	this->gID = "";
	this->gUser = "";
	this->gEmail = "";
}