#include <string>
#include <iostream>
#include <windows.h>
#include <Process.h>
#include <psapi.h>
#include <vector>

void ShowActiveProcesses(){
    std::vector<std::string> processes;
    DWORD aProcesses[1024], cbNeeded, cProcesses;
    unsigned int i;

    if ( !EnumProcesses( aProcesses, sizeof(aProcesses), &cbNeeded ) )
    {
        return;
    }
    cProcesses = cbNeeded / sizeof(DWORD);
    for ( i = 0; i < cProcesses; i++ ){
        if( aProcesses[i] != 0 ){
            TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>");
            HANDLE hProcess = OpenProcess( PROCESS_QUERY_INFORMATION |
                                           PROCESS_VM_READ,
                                           FALSE, aProcesses[i] );
            if (NULL != hProcess ){
                HMODULE hMod;
                DWORD cbNeeded;

                if ( EnumProcessModules( hProcess, &hMod, sizeof(hMod), &cbNeeded) ){
                    GetModuleBaseName(hProcess, hMod, szProcessName, sizeof(szProcessName)/sizeof(TCHAR) );
                }
            }
            processes.push_back(szProcessName);
            CloseHandle( hProcess );
        }
    }

    bool telegram_is_active = false;
    bool notepad_is_active = false;
    for (auto x : processes) {
        if (x == "Telegram.exe") {
            std::cout << "\nTelegram is active!";
            telegram_is_active = true;
        }
        if (x == "notepad.exe") {
            std::cout << "\nNotepad is active!";
            notepad_is_active = true;
        }
    }
    if(!notepad_is_active && !telegram_is_active){
        std::cout << "\nNone of the processes we are intressted in are running";
    }
}

int main(int argc,char **argv) {
    _putenv_s("PROC_TO_KILL", "notepad,Telegram");
    ShowActiveProcesses();
    std::string pf = getenv("PROC_TO_KILL");

    char lpszAppName[] = R"(..\Killer\cmake-build-debug\Killer.exe)"; //open Killer exe
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);
    if (CreateProcess(lpszAppName, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL,
                       NULL, &si, &pi)){
        Sleep(1000);
        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(pi.hThread);
        CloseHandle(pi.hProcess);
    } else{
        std::cout << "The meow process is not created.\n";
        return 0;
    }

    ShowActiveProcesses();
    _putenv("PROC_TO_KILL"); //delete
    return 0;
}