#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <sstream>
#include <string>
#include "../Sources/Headers/menu.h"
#include "../Sources/Headers/cmysql.h"
#include "../Sources/Headers/authenticate.h"

int main() {
	/*	Initializing parameters	*/
	SetConsoleTitle(L"Initializing...");
	SetConsoleOutputCP(65001);

	/*	Authentication process	*/
	{authenticate authenticateMainObj; authenticateMainObj.login(); }

	/*	Start the program	*/
	SetConsoleTitle(L"MySQL Log-in Demo");
	menu menuMainObj;
	while (true) {
		menuMainObj.ProcessOption(menuMainObj.SelectOption());
	}
	return 0;
}