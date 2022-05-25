#include <stdlib.h>
#include <string>
#include <iostream>
#include <winbase.h>
#include <windows.h>

int main(int argc,char **argv) {
    _putenv_s("PROC_TO_KIL", "notepad,telegram");
    return 0;
};
