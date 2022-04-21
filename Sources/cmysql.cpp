#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <sstream>
#include <string>
#include "../Sources/Headers/menu.h"
#include "../Sources/Headers/cmysql.h"
#include "../Sources/Headers/authenticate.h"
#include "../Sources/Headers/animation.h"

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

animation animationCMySQLObj; //	Create object to use 'animation' class functions

/*	Global Variables (For storing temporary data to transfer to another classes)	*/
std::string TempID;
std::string TempUser;
std::string TempEmail;


/*	Define 'cmysql' class functions	*/
void cmysql::Connect() {
	//- 1. Connect to MySQL Server
	try {
		driver = get_driver_instance();
		con = driver->connect(server, user, pwd);
		serverConnected = true;
	}
	catch (sql::SQLException e) {
		std::string TempString = e.what();
		std::string ErrorMsg1 = TempString.substr(0, 22);	// Incorrect user or password
		std::string ErrorMsg2 = TempString.substr(0, 20);	// Connection failed
		if (ErrorMsg1 == "Access denied for user") { std::cout << "Failed to connect to the MySQL server (Incorrect user or password)" << std::endl; exit(1); }
		else if (ErrorMsg2 == "Unable to connect to") { std::cout << "Failed to connect to the MySQL server (Timeout)" << std::endl; exit(1); }
		else { std::cout << e.what() << std::endl; exit(1); }
	}
	//- 2. Connect to Database
	try {
		con->setSchema(database);
		databaseConnected = true;
	}
	catch (sql::SQLException e) {
		std::string TempString = e.what();
		std::string ErrorMsg1 = TempString.substr(0, 16);	//	Database not found
		if (ErrorMsg1 == "Unknown database") { std::cout << "Failed to connect to the Database (Database not found)" << std::endl; exit(1); }
		else { std::cout << e.what() << std::endl; exit(1); }
	}
	if (serverConnected && databaseConnected) std::cout << "";
	else exit(1);
}

bool cmysql::Authenticate(std::string _inputUser, std::string _inputPwd) {
	try {
		std::string createQuery;
		createQuery = "SELECT * FROM account WHERE user=\"" + _inputUser + "\" AND pwd=\"" + _inputPwd + "\"";
		pstmt = con->prepareStatement(createQuery);
		result = pstmt->executeQuery();
		if (result->next()) {

			/*	Get datas to global variables upon success login	*/
			std::string i[3];
			i[0] = result->getString(1);
			i[1] = result->getString(2);
			i[2] = result->getString(4);
			TempID = i[0];
			TempUser = i[1];
			TempEmail = i[2];
			{std::cout << "> "; animationCMySQLObj.DotAnimation(100); std::cout << std::endl; }
			bool logon = true;
			return logon;
		}
		else {
			{std::cout << "> "; animationCMySQLObj.DotAnimation(100); std::cout << std::endl; std::cout << "Login failed (Incorrect user or password)" << std::endl; }
			bool logon = false;
			system("pause");
			return logon;
		}
	}
	catch (sql::SQLException e) {
		exit(1);
	}
}