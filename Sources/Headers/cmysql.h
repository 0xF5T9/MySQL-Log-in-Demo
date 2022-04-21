#pragma once
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <sstream>
#include <string>
#include "menu.h"
#include "cmysql.h"

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

class cmysql {
private:
	const std::string server = "tcp://localhost:3306";
	const std::string user = "root";
	const std::string pwd = "1284";
	const std::string database = "test";
	bool serverConnected = false;
	bool databaseConnected = false;
	sql::Driver* driver;
	sql::Connection* con;
	sql::Statement* stmt;
	sql::PreparedStatement* pstmt;
	sql::ResultSet* result;
public:
	cmysql() {
		//	Constructor
	}
	~cmysql() {
		//	Destructor
	}
	void Connect();
	bool Authenticate(std::string _inputUser, std::string _inputPwd);
};

