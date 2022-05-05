#pragma once
class global {
private:

	/*	Class Properties	*/
	std::string gID;
	std::string gUser;
	std::string gEmail;

public:

	

	global() {	//	Constructor

	}
	global(const global& _copy) {	//	Copy Constructor

	}
	~global() {	//	Destructor

	}

	/*	Class function prototypes	*/
	void SetValue(std::string _value, std::string _variable);
	std::string GetValue(std::string _variable);
	void Clear();
};

