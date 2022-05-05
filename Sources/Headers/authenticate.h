#pragma once
#include "../Sources/Headers/global.h"
#include "../Sources/Headers/cmysql.h"

class authenticate {
private:

	/*	Declare Object Pointers	*/
	global* Global;
	cmysql* CMySQL;

public:
	authenticate() {	//	Constructor
		
	}
	authenticate(global* _Global, cmysql* _CMySQL) {	//	Constructor (w/ Global & CMySQL Object)
		this->Global = _Global;
		this->CMySQL = _CMySQL;
	}
	authenticate(const authenticate& _copy) {	//	Copy Constructor

	}
	~authenticate() {	//	Destructor
		
	}

	/*	Class function prototypes	*/
	void Login();
};

