#ifndef LABA5_FSTREAM__LABA5_H
#define LABA5_FSTREAM__LABA5_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "laba5.h"

bool choice(std::string question,std::string true_answer,std::string false_answer);
std::string enter_name(std::string standard_name, bool flag);
void vec_in_console(std::vector<std::string> vec);

void input(std::vector<std::string> &vec);
void print_input(std::vector<std::string> &vec);
int items_in_string( std::string str);
void output(std::vector<std::string> &str);

#endif
