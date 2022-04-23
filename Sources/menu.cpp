#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <sstream>
#include <string>
#include "../Sources/Headers/menu.h"
#include "../Sources/Headers/cmysql.h"
#include "../Sources/Headers/authenticate.h"
#include "../Sources/Headers/animation.h"
#include "../Sources/Headers/global.h"

animation animationMenuObj;	//	Create object to use 'animation' class functions

/*	Define 'menu' class functions	*/
void menu::ShowMenu() {
	std::cout << "Welcome " << _user << "." << std::endl;
	std::cout << "ID: " << _id << std::endl;
	std::cout << "Email: " << _email << std::endl;
	std::cout << std::endl;
	std::cout << "1. Quit the program" << std::endl;
	std::cout << std::endl;
}

int menu::SelectOption() {
	int option;
	bool ValidOption = false;
	while (ValidOption == false) {
		system("cls");
		ShowMenu();
		std::cout << "Select option: ";
		std::cin >> option;
		if (option > 0 && option < 2) {
			ValidOption = true;
		}
		std::cin.clear();
		std::cin.ignore(10000, '\n');
	}
	return option;
}

void menu::ProcessOption(int _option) {
	switch (_option) {
	case 1:
		system("cls");
		ShowMenu();
		{std::cout << "> "; animationMenuObj.DotAnimation(100); }
		exit(0);
		break;
	default:
		break;
	}
}