#pragma once

/*	Get global variables (From: cmysql.cpp)	*/
extern std::string TempID;
extern std::string TempUser;
extern std::string TempEmail;

class menu {
private:
	std::string _id;
	std::string _user;
	std::string _email;
public:
	menu() : _id(TempID), _user(TempUser), _email(TempEmail) {	/*	Load data from global variables on initial constructor	*/
		//	Constructor

		/*	Set global variables to NULL	*/
		TempID = "", TempUser = "", TempEmail = "";
	}
	~menu() {
		//	Destructor
	}
	void ShowMenu();
	int SelectOption();
	void ProcessOption(int _option);
};

