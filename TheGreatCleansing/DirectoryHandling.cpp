#include "DirectoryHandling.h"

#include <iostream>
#include <filesystem>

#include "UserInputManager.h"
#include "RegistryHandling.h"
#include "vdf_parser.hpp"



std::wstring DirectoryHandling::EvaluateGamePath()
{

    std::wstring steamPath = RegistryHandling::FindSteamInstallationPath();

    std::wstring libraryVDFPath = steamPath.append(L"\\steamapps\\libraryfolders.vdf");

    std::wifstream file(libraryVDFPath);

    auto root = tyti::vdf::read(file);
    
    std::wstring attribute;
    std::wstring baseGameFolderPath;

    for(int i = 0; i < root.childs.size(); i++)
    {

        auto child = root.childs[std::to_wstring(i)];
        attribute = child->childs[L"apps"]->attribs[L"6020"];

        if(!attribute.empty())
        {
            baseGameFolderPath = child->attribs[L"path"];
            break;
        }
    }

    std::wstring GameFolderPath = baseGameFolderPath.append(L"\\steamapps\\common");

    return GameFolderPath;
}


void DirectoryHandling::DeleteGameFolder()
{
    
    if(UserInputManager::ReceiveUserInput() == 1)
    {
        std::error_code error;
        std::wstring GameFolderPath = EvaluateGamePath();
        uintmax_t test = std::filesystem::remove_all(GameFolderPath + L"\\Jedi Academy\\GameData\\MBII", error);
        if(test == 0)
        {
            system("cls");
            std::cout << "You already have been cleansed\n" << std::endl;
            
        }
        else
        {
            system("cls");
            std::cout << "You have been cleansed of: " << test << " sins...\n" << std::endl;
        }
        system("pause");
    }
    else
    {
        exit(1);
    }
    

}
