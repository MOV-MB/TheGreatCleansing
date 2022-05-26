#include "RegistryHandling.h"
#include <string>
#include <Windows.h>

//Computer\HKEY_LOCAL_MACHINE\SOFTWARE\WOW6432Node\Valve\Steam InstallPath

LONG RegistryHandling::GetStringRegKey(HKEY hKey, const std::wstring& strValueName, std::wstring& strValue,
                     const std::wstring& strDefaultValue)
{
    strValue = strDefaultValue;
    WCHAR szBuffer[512];
    DWORD dwBufferSize = sizeof(szBuffer);
    ULONG nError = RegQueryValueEx(hKey, strValueName.c_str(), nullptr, nullptr, (LPBYTE)szBuffer, &dwBufferSize);
    if (ERROR_SUCCESS == nError)
    {
        strValue = szBuffer;
    }
    return nError;
}

std::wstring RegistryHandling::FindSteamInstallationPath()
{
    HKEY hKey;
    LONG lRes = RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"SOFTWARE\\WOW6432Node\\Valve\\Steam", NULL, KEY_READ, &hKey);
    bool bExistsAndSuccess(lRes == ERROR_SUCCESS);
    bool bDoesNotExistsSpecifically(lRes == ERROR_FILE_NOT_FOUND);
    std::wstring strValueOfBinDir;
    const std::wstring strKeyDefaultValue;
    GetStringRegKey(hKey, L"InstallPath", strValueOfBinDir, strKeyDefaultValue);
    return strValueOfBinDir;
}
