#pragma once
class menu {
private:
	std::string _id;
	std::string _user;
	std::string _email;
public:
	menu() {
		//	Constructor
		/*	Declare global variables	*/
		extern std::string TempID;
		extern std::string TempUser;
		extern std::string TempEmail;
		/*	Load data from global variables	*/
		this->_id = TempID;
		this->_user = TempUser;
		this->_email = TempEmail;
		/*	Set global variables to NULL	*/
		TempID, TempUser, TempEmail = "";
	}
	~menu() {
		//	Destructor
	}
	void ShowMenu();
	int SelectOption();
	void ProcessOption(int _option);
};

