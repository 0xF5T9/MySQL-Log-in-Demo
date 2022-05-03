#pragma once
class global {
private:

public:

	/*	Class Properties	*/
	std::string gID;
	std::string gUser;
	std::string gEmail;

	global() {	//	Constructor

	}
	global(const global& _copy) {	//	Copy Constructor

	}
	~global() {	//	Destructor

	}

	/*	Class function prototypes	*/
	void Clear();
};

