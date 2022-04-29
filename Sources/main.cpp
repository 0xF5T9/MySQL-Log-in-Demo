#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <sstream>
#include <string>
#include "../Sources/Headers/menu.h"
#include "../Sources/Headers/cmysql.h"
#include "../Sources/Headers/authenticate.h"
#include "../Sources/Headers/global.h"

/*	Global Object (For storing tempory datas)	*/
global GlobalObject;

int main() {

	/*	Initialize program parameters	*/
	SetConsoleTitle(L"Initializing...");
	SetConsoleOutputCP(65001);	//* UTF-8 Code Page Support

	
	{	/*	Authentication process	*/
		authenticate authMO(GlobalObject);	//*1	Create authenticate object & passing Global Object to 'authenticate' class
		authMO.login();	//*2	Begin login process
	}	


	{	/*	Start the menu	*/
		SetConsoleTitle(L"MySQL Log-in Demo");
		menu menuMO(GlobalObject); //*	Passing Global Object to 'menu' class
		while (true) {
		menuMO.ProcessOption(menuMO.SelectOption());
		}
	}
	return 0;
}