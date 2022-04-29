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
void authenticate::login() {
	//- 1. Connect to MySQL Server & Database
	SetConsoleTitle(L"Connecting...");
	cmysql cmysqlAO(*GlobalObject);	//*1	Create cmysql object & passing Global Object to 'cmysql' class
	cmysqlAO.Connect();

	//- 2. Checking if the user & password is exists & matches.
	SetConsoleTitle(L"Please log-in to continue");
	while (true) {
		system("cls");
		std::string iUser, iPwd;
		std::cout << "Enter username: ";
		std::getline(std::cin, iUser);
		std::cout << "Enter password: ";
		std::getline(std::cin, iPwd);
		bool LogOn = cmysqlAO.Authenticate(iUser, iPwd);
		if (LogOn == true) break;
	}
	system("cls");
}