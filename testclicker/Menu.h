#pragma once
//Menu.h, Used to handle drawing code for menu

#include <stdio.h>
#include <thread>

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
		printf("%s   ________                   _________      __            ", RED);
		std::cout << "         Min CPS = " << minCPS << "\n";
		printf("%s  / ____/ /__  ____ ______   / ____/ (_)____/ /_____  _____", GRN);
		std::cout << "         Max CPS = " << maxCPS << "\n";                          
		printf("%s / /   / / _ \\/ __ `/ ___/  / /   / / / ___/ //_/ _ \\/ ___/", YEL);
		printf("%s         State = ", YEL);
		if (!toggled) { printf("%s [ OFF ]\n", RED); }
		if (toggled) { printf("%s [ ON ]\n", GRN); }
		printf("%s/ /___/ /  __/ /_/ / /     / /___/ / / /__/ ,< /  __/ /    \n", BLU);
		printf("%s\\____/_/\\___/\\__,_/_/      \\____/_/_/\\___/_/|_|\\___/_/     \n\n", MAG);	
		if (initbool) { 
			initbool = false;
			printf("%sPlease choose your Min CPS: ", RED);
			std::cin >> minCPS;
			SetCursorrPosition(0, 6);
			std::cout << "                                          ";
			SetCursorrPosition(0, 6);
			printf("%sPlease choose your Max CPS: ", RED);
			std::cin >> maxCPS;
			SetCursorrPosition(0, 6);
			std::cout << "                                          ";
			SetCursorrPosition(0, 6);
			system("cls");
			print_menu(minCPS, maxCPS, toggled, initbool);
		}
	}
};
