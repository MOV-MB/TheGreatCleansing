#pragma once
#include <string>

class DirectoryHandling
{
public:
    static void DeleteGameFolder();
private:
    static std::wstring EvaluateGamePath();
    
};

