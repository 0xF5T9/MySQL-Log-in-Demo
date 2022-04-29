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

animation animMenuO;	//	Create object to use 'animation' class functions

/*	Define 'menu' class functions	*/
void menu::ShowMenu() const {
	std::cout << "Welcome " << _user << "." << std::endl;
	std::cout << "ID: " << _id << std::endl;
	std::cout << "Email: " << _email << std::endl;
	std::cout << std::endl;
	std::cout << "1. Quit the program" << std::endl;
	std::cout << std::endl;
}

int menu::SelectOption() {
	int iOption;
	bool ValidOption = false;
	while (ValidOption == false) {
		system("cls");
		ShowMenu();
		std::cout << "Select Option: ";
		std::cin >> iOption;
		if (iOption > 0 && iOption < 2) {
			ValidOption = true;
		}
		std::cin.clear();
		std::cin.ignore(10000, '\n');
	}
	return iOption;
}

void menu::ProcessOption(int _Option) {
	switch (_Option) {
	case 1:
		system("cls");
		ShowMenu();
		{std::cout << "> "; animMenuO.DotAnimation(100); }
		exit(0);
		break;
	default:
		break;
	}
}