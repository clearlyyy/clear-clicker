#pragma once
//Menu.h, Used to handle drawing code for menu

#include <stdio.h>
#include <thread>
#include "color.hpp"

//Color shit for printf
#define NRM  "\x1B[0m"
#define RED  "\x1B[31m"
#define GRN  "\x1B[32m"
#define YEL  "\x1B[33m"
#define BLU  "\x1B[34m"
#define MAG  "\x1B[35m"
#define CYN  "\x1B[36m"
#define WHT  "\x1B[37m"

// could've just shoved this class inside of testclicker.cpp.
class Menu
{
public:
	Menu(float& minCPS, float& maxCPS, bool toggled, bool& initbool) // this inits everything and as soon as a "Menu" is created inside the code it will run print_menu()
	{
		this->print_menu(minCPS, maxCPS, toggled, initbool);
	}
	void SetCursorrPosition(int x, int y) // function is used to set cursor position on the console, so i can write to it.
	{
		HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD pos = { x, y };
		SetConsoleCursorPosition(output, pos);
	}
	//i should've used a fucking GUI.
	void print_menu(float& minCPS, float& maxCPS, bool toggled, bool& initbool)
	{
		//this shit probably looks cryptic, but its just printing the menu.
		
		std::cout << dye::red("   ________                   _________      __            ");
		std::cout << "         Min CPS = " << minCPS << "\n";
		std::cout << dye::green("  / ____/ /__  ____ ______   / ____/(_)_____/ /_____  _____");
		std::cout << "         Max CPS = " << maxCPS << "\n";                          
		std::cout << dye::yellow(" / /   / / _ \\/ __ `/ ___/  / /   / / / ___/ //_/ _ \\/ ___/");
		std::cout << dye::yellow("         State = ");
		if (!toggled) { std::cout << dye::red(" [ OFF ]\n"); }
		if (toggled) { std::cout << dye::green(" [ ON ]\n"); }
		std::cout << dye::blue("/ /___/ /  __/ /_/ / /     / /___/ / / /__/ ,< /  __/ /    \n");
		std::cout << dye::purple("\\____/_/\\___/\\__,_/_/      \\____/_/_/\\___/_/|_|\\___/_/     \n\n");	
		if (initbool) { 
			initbool = false;
			std::cout << dye::red("Please choose your Min CPS: ");
			std::cin >> minCPS;
			SetCursorrPosition(0, 6);
			std::cout << "                                          ";
			SetCursorrPosition(0, 6);
			std::cout << dye::red("Please choose your Max CPS: ");
			std::cin >> maxCPS;
			SetCursorrPosition(0, 6);
			std::cout << "                                          ";
			SetCursorrPosition(0, 6);
			system("cls");
			print_menu(minCPS, maxCPS, toggled, initbool);
		}
	}
};
