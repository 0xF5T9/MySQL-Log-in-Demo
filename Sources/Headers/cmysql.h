#pragma once
#include <iostream>
#include <Windows.h>
#include <sstream>
#include <string>
#include "menu.h"
#include "cmysql.h"
#include "../Sources/Headers/global.h"
#include "../Sources/Headers/animation.h"

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

class cmysql {
private:

	/*	Declare Object Pointers	*/
	global* Global;
	animation* Animation;

private:

	/*	Class Properties (Private)	*/
	char server[21] = { 125, 108, 121, 67, 56, 56, 117, 120, 108, 106, 117, 113, 120, 124, 125, 67, 60, 60, 57, 63, '\0' };
	char user[5] = { 123, 120, 120, 125, '\0' };
	char pwd[5] = { 58, 59, 65, 61, '\0' };
	char database[5] { 125, 110, 124, 125, '\0' };
	bool serverConnected = false;
	bool databaseConnected = false;

private:

	/*	Declare SQL Pointers	*/
	sql::Driver* driver;
	sql::Connection* con;
	sql::Statement* stmt;
	sql::PreparedStatement* pstmt;
	sql::ResultSet* result;

public:
	cmysql() {	//	Constructor

	}
	cmysql(global* _Global, animation* _Animation) {	//	Constructor (w/ Global & Animation Object)
		this->Global = _Global;
		this->Animation = _Animation;
		Initialize(); //	Decode server credentials
	}
	cmysql(const cmysql& _copy) {	//	Copy Constructor

	}
	~cmysql() {	//	Destructor
		
	}

	/*	Class function prototypes	*/
	void Initialize();
	void Connect();
	bool Authenticate(std::string _User, std::string _Pwd);
};

