#include <iostream>
#include <Windows.h>
#include <sstream>
#include <string>
#include "../Sources/Headers/menu.h"
#include "../Sources/Headers/cmysql.h"
#include "../Sources/Headers/authenticate.h"
#include "../Sources/Headers/global.h"
#include "../Sources/Headers/func.h"

int main() {

	/*	Initialize program parameters	*/
	SetConsoleTitle(L"Initializing...");
	SetConsoleOutputCP(65001);	// Set code page utf-8
	animation* Animation = CreateObjectAnimation();
	global* Global = CreateObjectGlobal();
	cmysql* CMySQL = CreateObjectCMySQL(Global, Animation);
	authenticate* Authenticate = CreateObjectAuthenticate(Global, CMySQL);
	menu* Menu = CreateObjectMenu(Global, Animation);

	/*	Start the program	*/
	Authenticate->Login();
	Menu->Initialize();
	SetConsoleTitle(L"MySQL Log-in Demo");
	while (true) {
		bool EXITPROGRAM = Menu->ProcessOption(Menu->SelectOption());
		if (EXITPROGRAM == true) break;
	}

	/*	End the program	*/
	FreeMemory(Animation);
	FreeMemory(Global);
	FreeMemory(CMySQL);
	FreeMemory(Authenticate);
	FreeMemory(Menu);
	return 0;
}