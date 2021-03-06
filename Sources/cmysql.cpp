#include <iostream>
#include <Windows.h>
#include <sstream>
#include <string>
#include "../Sources/Headers/menu.h"
#include "../Sources/Headers/cmysql.h"
#include "../Sources/Headers/authenticate.h"
#include "../Sources/Headers/animation.h"
#include "../Sources/Headers/global.h"

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

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

bool cmysql::Authenticate(std::string _User, std::string _Pwd) {
	try {
		std::string CreateQuery;
		CreateQuery = "SELECT * FROM account WHERE user=\"" + _User + "\" AND pwd=\"" + _Pwd + "\"";
		pstmt = con->prepareStatement(CreateQuery);
		result = pstmt->executeQuery();
		if (result->next()) {

			/*	Get datas to global object upon success login	*/
			std::string i[3];
			i[0] = result->getString(1);
			i[1] = result->getString(2);
			i[2] = result->getString(4);
			Global->SetValue(i[0], "gID");
			Global->SetValue(i[1], "gUser");
			Global->SetValue(i[2], "gEmail");
			{std::cout << "> "; Animation->DotAnimation(100); std::cout << std::endl; }
			bool LogOn = true;
			return LogOn;
		}
		else {
			{std::cout << "> "; Animation->DotAnimation(100); std::cout << std::endl; std::cout << "Login failed (Incorrect user or password)" << std::endl; }
			bool LogOn = false;
			system("pause");
			return LogOn;
		}
	}
	catch (sql::SQLException e) {
		{std::cout << "> "; Animation->DotAnimation(100); std::cout << std::endl; std::cout << "Connection lost." << std::endl; }
		exit(1);
	}
}

void cmysql::Initialize() {
	/*	A soft hardcode layer protect server credentials against casual hex reader.	*/
	for (int i = 0; i < 20; i++) {
		server[i] = server[i] + 8;
		server[i] = server[i] + 3;
		server[i] = server[i] + 1;
		server[i] = server[i] + 7;
		server[i] = server[i] - 9;
		server[i] = server[i] - 5;
		server[i] = server[i] - 9;
		server[i] = server[i] - 5;
	}
	for (int i = 0; i < 4; i++) {
		user[i] = user[i] + 8;
		user[i] = user[i] + 3;
		user[i] = user[i] + 1;
		user[i] = user[i] + 7;
		user[i] = user[i] - 9;
		user[i] = user[i] - 5;
		user[i] = user[i] - 9;
		user[i] = user[i] - 5;
	}
	for (int i = 0; i < 4; i++) {
		pwd[i] = pwd[i] + 8;
		pwd[i] = pwd[i] + 3;
		pwd[i] = pwd[i] + 1;
		pwd[i] = pwd[i] + 7;
		pwd[i] = pwd[i] - 9;
		pwd[i] = pwd[i] - 5;
		pwd[i] = pwd[i] - 9;
		pwd[i] = pwd[i] - 5;
	}
	for (int i = 0; i < 4; i++) {
		database[i] = database[i] + 8;
		database[i] = database[i] + 3;
		database[i] = database[i] + 1;
		database[i] = database[i] + 7;
		database[i] = database[i] - 9;
		database[i] = database[i] - 5;
		database[i] = database[i] - 9;
		database[i] = database[i] - 5;
	}
}
