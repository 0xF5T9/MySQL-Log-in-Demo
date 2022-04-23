#pragma once
#include "../Sources/Headers/global.h"
class menu {
private:
	std::string _id;
	std::string _user;
	std::string _email;
public:
	menu(global &o) {
		//	Constructor

		/*	Load datas from global object via constructor	*/
		this->_id = o.gID;
		this->_user = o.gUser;
		this->_email = o.gEmail;
		o.Clear();
	}
	~menu() {
		//	Destructor
	}
	void ShowMenu();
	int SelectOption();
	void ProcessOption(int _option);
};

