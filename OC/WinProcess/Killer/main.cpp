#include <iostream>
#include <string>
#include <cstdio>
#include <windows.h>
#include <tlhelp32.h>
#include <cstdlib>

bool KillProcessByName(std::string processName){
    bool success = false;
    PROCESSENTRY32 entry;
    entry.dwSize = sizeof(PROCESSENTRY32);

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
    if (Process32First(snapshot, &entry) == TRUE){
        while (Process32Next(snapshot, &entry) == TRUE){
            if (entry.szExeFile == processName){
                HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, entry.th32ProcessID);
                if(TerminateProcess(hProcess, 1)){
                    success = true;
                }
                CloseHandle(hProcess);
            }
        }
    }
    CloseHandle(snapshot);
    return success;
}

bool KillProcessById(long long processId){
    bool success = false;
    HANDLE hProcess;
    if (!(hProcess = OpenProcess(PROCESS_TERMINATE, 0, (DWORD)processId))){
        if(TerminateProcess(hProcess, 1)){
            success = true;
        }
        CloseHandle(hProcess);
    } else{
        std::cout << "couldn't find process";
    }
    return success;
}

int main(int argc, char* argv[]) {
    std::cout << "Would you...\n";
    int answ;
    std::cout << "1 -- kill process by name\n";
    std::cout << "2 -- kill process by id\n";
    std::cout << "3 -- kill all processes in PROC_TO_KILL\n";
    std::cout << "4 -- exit\n";
    while(true){
        std::cout << "Choose option from the menu: ";
        std::cin >> answ;
        switch (answ) {
            case 1:{
                std::cout << "\nEnter process name: ";
                std::string procName;
                std::cin >> procName;

                if(KillProcessByName(procName)){
                    std::cout << "Success!\n";
                } else{
                    std::cout << ":(\n";
                }
                break;
            }
            case 2:{
                std::cout << "\nEnter process id: ";
                int procId;
                std::cin >> procId;

                if(KillProcessById(procId)){
                    std::cout << "Success!\n";
                } else{
                    std::cout << ":(\n";
                }
                break;
            }
            case 3:{
                std::string proc_to_kill = getenv("PROC_TO_KILL");
                std::cout << proc_to_kill;

                size_t pos = 0;
                std::string token;
                while ((pos = proc_to_kill.find(",")) != std::string::npos) {
                    KillProcessByName(proc_to_kill.substr(0, pos)+".exe");
                    proc_to_kill.erase(0, pos + 1);
                }
                KillProcessByName(proc_to_kill.substr(0, pos)+".exe");
                break;
            }
            case 4:{
                return 0;
            }
        }

    }
}