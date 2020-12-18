#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "laba5.h"

enum {
    NUMBERS = 0,
    LETTERS = 1,
    TRASH = 2,
};

bool choice(std::string question,std::string true_answer,std::string false_answer){
    std::cout<<question<<'\n';
    std::cout<<true_answer<<" - 1\n";
    std::cout<<false_answer<<" - 0\n";
    bool flag;
    std::cin >> flag;
    std::cout<<'\n';
    return flag;
}

std::string enter_name(std::string standard_name, bool flag){
    std::string file_name(standard_name);
    if(!flag){
        std::cout<<"Enter name of the file: \n";
        std::cin>>file_name;
    }
    std::cout<<'\n';
    return file_name+".txt";
}

void vec_in_console(std::vector<std::string> vec){
    for(int i=0; i<vec.size(); ++i) {
        std::cout << vec[i]<<'\n';
    }
    std::cout<<'\n';
}

void input(std::vector<std::string> &vec){

    bool flag=choice("Would you use standard input file or use your own?",
                     "standard", "custom");
    std::string input_name=enter_name("some",flag);
    std::ifstream fin(input_name);

    std::string line;
    while(!fin.eof()) {
        std::getline(fin, line, '\n');
        vec.push_back(line);
    }
    fin.close();
}

void print_input(std::vector<std::string> &vec){
    bool flag=choice("Would you see text from input file?","yes", "no");

    if(flag){
        vec_in_console(vec);
    }
}

int items_in_string( std::string str){
    int flag_for_numb=1, flag_for_letters=1;
    for(int i=0; i<str.size(); i++){
        if(str[i]<48 || str[i]>57){
            flag_for_numb=0;
        }
        if(str[i]<65 || (str[i]>90 && str[i]<97) || str[i]>122){
            flag_for_letters=0;
        }
    }
    if(flag_for_numb == 0){
        if(flag_for_letters == 0){
            return TRASH;
        }
        else{
            return LETTERS;
        }
    }
    else{
        return NUMBERS;
    }
}


void output(std::vector<std::string> &str){
    bool flag = choice("Would you use standard output files or use your own?",
                       "standard", "custom");

    if(!flag) std::cout<<"Strings with numbers\n";
    std::string num_file=enter_name("numbers",flag);
    if(!flag) std::cout<<"Strings with letters\n";
    std::string let_file=enter_name("letters",flag);


    std::ofstream num_out(num_file);
    std::ofstream let_out(let_file);

    std::vector<std::string> num_vec;
    std::vector<std::string> let_vec;

    for (int i=0; i<str.size(); ++i) {
        int flag = items_in_string(str[i]);
        if ((num_out.is_open()) && (flag == NUMBERS)) {
            num_vec.push_back(str[i]);
            num_out << str[i] << '\n';
        } else {
            if ((let_out.is_open()) && (flag == LETTERS)) {
                let_vec.push_back(str[i]);
                let_out << str[i] << '\n';
            }
        }
    }
    num_out.close();
    let_out.close();

    bool flag_out = choice("Would you see text from output files?", "yes", "no");
    if(flag_out){
        std::cout << char (34) << num_file <<char (34) << ":\n";
        vec_in_console(num_vec);
        std::cout << char (34) << let_file <<char (34) << ":\n";
        vec_in_console(let_vec);
    }
}

