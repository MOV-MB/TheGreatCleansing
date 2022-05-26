#include "UserInputManager.h"
#include <Windows.h>
#include <iostream>

int UserInputManager::ReceiveUserInput()
{
    HANDLE hConsole;
    WORD color = 12;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole,color);

    std::string choice;

    while(true)
    {
        std::cout << "Do you want to cleanse your sins?:\n" << std::endl;
        std::cin >> choice;

        if(strcmp(choice.c_str(),"Y") != 0)
        {
            return 1;
        }
        if(strcmp(choice.c_str(),"N") != 0)
        {
            return 0;
        }
    
    }
    
}
