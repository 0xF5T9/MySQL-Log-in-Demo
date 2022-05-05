#pragma once
#include "../Sources/Headers/global.h"
#include "../Sources/Headers/animation.h"

class menu {
private:

	/*	Declare Object Pointers	*/
	global* Global;
	animation* Animation;

private:

	/*	Class Properties (Private)	*/
	std::string _id;
	std::string _user;
	std::string _email;

public:
	menu() {	//	Constructor

	}
	menu(global* _Global, animation* _Animation) {	//	Constructor
		this->Global = _Global;
		this->Animation = _Animation;
	}
	menu(const menu& _copy) {	//	Copy Constructor

	}
	~menu() {	//	Destructor
		
	}

	/*	Class function prototypes	*/
	void Initialize();
	void ShowMenu() const;
	int SelectOption();
	bool ProcessOption(int _option);
};

