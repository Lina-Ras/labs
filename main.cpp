/*Вариант 3.
Разбить исходный файл на два выходных: в первом файле должны идти строки, содержащие только цифры,
во втором – строки, содержащие только латинские буквы.
Порядок строк выходных файлов должен соответствовать их порядку во входном файле.
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "laba5.h"

int main() {

    std::vector<std::string> vec_of_str;
    input(vec_of_str);
    print_input(vec_of_str);
    output(vec_of_str);
    return 0;
}
