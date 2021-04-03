// testclicker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//
//

#include <iostream>
#include <Windows.h>
#include "Menu.h"
#include <random>
#include <iomanip>
#include <stdlib.h>

void SetCursorPosition(int x, int y);


float random_float(float a, float b) // This function generates a random float within a range of values,
    
    // instead of using rand(), this attempts to remove the bias that is usually associated with rand.
{
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<float> distr(a, b);
    
    return distr(eng);
}


void Clicker(float CPS, float minCPS, float maxCPS, bool toggled, bool lbutton_check, HWND hwnd) //this function handles all of the clicking mechanisms.
{
   
    while (toggled && GetAsyncKeyState(VK_LBUTTON))
    {
        hwnd = GetForegroundWindow();
        CPS = random_float(minCPS, maxCPS);
        SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, 0);
        Sleep(500 / CPS);
        SendMessage(hwnd, WM_LBUTTONUP, 0, 0);
        Sleep(500 / CPS);
        SetCursorPosition(6, 6);
        std::cout << std::setprecision(4) << CPS;
    }
                
      
}

 //main() is where the program enters upon startup, this inits all variables, and sets default values for the user.
 // 
int main()
{
    HWND minecraft = GetForegroundWindow();
    float CPS = 0;
    float minCPS = 69;
    float maxCPS = 420;
    bool toggled = false;
    bool initbool = true;
    bool LBUTTON_IS_DOWN = false;
    Menu menu(minCPS, maxCPS, toggled, initbool);
    std::cout << "CPS = " << CPS;
    while (true)
    {   
        if (GetAsyncKeyState(0x46)) {
            toggled = !toggled;
            system("cls");
            Menu menu(minCPS, maxCPS, toggled, initbool);
            Sleep(100);
            std::cout << "CPS = " << CPS ;
        }
        Clicker(CPS, minCPS, maxCPS, toggled, LBUTTON_IS_DOWN, minecraft);
    }
}

void SetCursorPosition(int x, int y) // function is used to set cursor position on the console, so i can write to it.
    //instead of rapidly refreshing the console every frame, im just setting a cursor position in the console and editing certain parts whenever
    //i need to.
{
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { x, y };
    SetConsoleCursorPosition(output, pos);
}

