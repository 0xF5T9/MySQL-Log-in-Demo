#pragma once
#include "../Sources/Headers/global.h"
class menu {
private:
	std::string _id;
	std::string _user;
	std::string _email;
public:
	menu(global &GlobalObject) {
		//	Constructor

		/*	Load datas from global object via constructor	*/
		this->_id = GlobalObject.gID;
		this->_user = GlobalObject.gUser;
		this->_email = GlobalObject.gEmail;
		GlobalObject.Clear();
	}
	~menu() {
		//	Destructor
	}
	void ShowMenu() const;
	int SelectOption();
	void ProcessOption(int _Option);
};

