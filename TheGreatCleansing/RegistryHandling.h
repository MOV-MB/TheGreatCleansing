#pragma once
#include <string>
#include <Windows.h>

class RegistryHandling
{
private:
    static LONG GetStringRegKey(HKEY hKey, const std::wstring& strValueName, std::wstring& strValue,
                                const std::wstring& strDefaultValue);
public:
    static std::wstring FindSteamInstallationPath();

};

