#pragma once
#include "../Sources/Headers/global.h"

class authenticate {
private:
	global* GlobalObject;
public:
	authenticate(global& GlobalObject) {
		//	Constructor
		this->GlobalObject = &GlobalObject;
	}
	~authenticate() {
		//	Destructor
	}
	void login();
};

