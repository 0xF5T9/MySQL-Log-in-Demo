#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <sstream>
#include <string>
#include "../Sources/Headers/menu.h"
#include "../Sources/Headers/cmysql.h"
#include "../Sources/Headers/authenticate.h"
#include "../Sources/Headers/global.h"

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

/*	Define 'authenticate' class functions	*/
void authenticate::login(global& o) {
	//- 1. Connect to MySQL Server & Database
	SetConsoleTitle(L"Connecting...");
	cmysql cmysqlAuthenticateObj; cmysqlAuthenticateObj.Connect();

	//- 2. Checking if the user & password is exists & matches.
	SetConsoleTitle(L"Please log-in to continue");
	while (true) {
		system("cls");
		std::string inputUser, inputPwd;
		std::cout << "Enter username: ";
		std::getline(std::cin, inputUser);
		std::cout << "Enter password: ";
		std::getline(std::cin, inputPwd);
		bool logon = cmysqlAuthenticateObj.Authenticate(inputUser, inputPwd, o); //*	Passing Global Object to use in 'Authenticate' function
		if (logon == true) break;
	}
	system("cls");
}