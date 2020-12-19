#ifndef STACKONARRAY_CALCULATOR_H
#define STACKONARRAY_CALCULATOR_H
#include <iostream>
#include <vector>
#include <sstream>
#include "StackOnArray.h"

enum PRIORITY{
    separator, //0
    open, //1
    close, //2
    low, //3
    medium, //4
    high, //5
};

int PriorityCheck(char test){
    switch (test) {
        case ',': return separator;
        case '(': return open;
        case ')': return close;
        case '+': return low;
        case '-': return low;
        case '*': return medium;
        case '/': return medium;
    }
};

bool signs(char &tmp){
    return (tmp == '+')||(tmp == '-')||(tmp == '*')||(tmp == '/');
};

bool numbers(char &tmp){
    return ((tmp <= '9')&& (tmp >= '0')) || (tmp=='.');
}

bool brackets (char &tmp){
    return (tmp == '(')||(tmp == ')');
}

bool isNegative(char a, char b, char c){
    return a=='(' && b=='-' && numbers(c);
}

bool signsWithoutMinus(char &tmp){
    return (tmp == '+')||(tmp == '*')||(tmp == '/');
};

bool isCorrect(std::string str){
    if(signs(str[0]) || str[0] == ')')
        return false;
    if(signs(str[str.size() - 1]) || str[str.size()-1] == '(')
        return false;

    int open = 0;
    int close = 0;
    for (int i = 0; i < str.size(); ++i){
        if (i!=0 && signs(str[i]) && signs(str[i-1]))
            return false;
        if (str[i] == '(') {
            ++open;
            if ((i < str.size() - 1) && (signsWithoutMinus(str[i+1]) || str[i+1] == ')'))
                return false;
            if(i!=0 && (numbers(str[i-1]) || str[i-1] == ')' )){
                return false;
            }
        }
        if (str[i] == ')'){
            ++close;
            if ((i!=0) && (signs(str[i-1])))
                return false;
            if((i < str.size() - 1) && (numbers(str[i+1]) || str[i+1] == '(' )){
                return false;
            }
        }
    }
    return close==open;
}

std::string Convert(std::string input){
    std::string output;
    while (!input.empty()){
        int counter=2;
        if(input.size()>3 && input[0] == '(' && input[1] == '-' && numbers(input[2])){
            while(!signs(input[counter]) && !brackets(input[counter]) && counter<input.size() ){
                ++counter;
            }
            if (input[counter] != ')'){
                output+='(';
            }
            for(int i=0; i< counter; ++i){
                output+=input[i];
            }
            output += ')';
            if (input[counter] == ')'){
                ++counter;
            }
            input.erase(0,counter);
        }

        counter = 1;
        if(input.size()>1 &&input[0] == '-' && numbers(input[1])){
            while(!signs(input[counter]) && !brackets(input[counter]) && counter<input.size()){
                ++counter;
            }
            if(!output.empty()){
                output+='+';
            }
            output+='(';
            for(int i=0; i< counter; ++i){
                output+=input[i];
            }
            output+=')';
            input.erase(0,counter);
        } else{
            output+= input[0];
            input.erase(0,1);
        }
    }
    return output;
};

std::string ToPN(std::string str){
    str = Convert(str);
    if(!isCorrect(str)){
        throw ("This isn't correct!");
    }
    char tmp;
    StackOnArray<char> sign;
    std::string output;
    bool wasNumber(true);
    bool wasNegative(false);
    while(!str.empty()){
        tmp = str[0];
        str.erase(0,1);

        if (numbers(tmp)){
            if(!wasNumber){
                output+=',';
            }
            output += tmp;
            wasNumber = true;
        }
        if(signs(tmp)||brackets(tmp)){
            switch (tmp) {
                case '(':{
                    if(isNegative(tmp, str[0], str[1])){
                        if(!wasNumber){
                            output+=',';
                        }
                        output += '-';
                        str.erase(0,1);
                        wasNumber = true;
                        wasNegative = true;
                    } else {
                        sign.push(tmp);
                        wasNumber = false;
                    }
                    break;
                }
                case ')':{
                    if (wasNegative){
                        wasNegative = false;
                        wasNumber = true;
                    }else{
                        while (sign.top()!='(') {
                            output += ',';
                            output += sign.pop();
                        }
                        sign.pop();
                        wasNumber = false;
                    }
                    break;
                }
                default:{
                    if(!sign.isEmpty()) {
                        while (PriorityCheck(sign.top()) >= PriorityCheck(tmp)) {
                            output += ',';
                            output += sign.pop();
                            if(sign.isEmpty()){break;}
                        }
                    }
                    sign.push(tmp);
                    wasNumber = false;
                    break;
                }
            }
        }
    }
    while (!sign.isEmpty()){
        output += ',';
        output += sign.pop();
    }
    if(output[0] == ',') {
        output.erase(0, 1);
    }
    return output;
}

double FromPN(std::string str){
    StackOnArray<double> number;
    std::string tmp;
    int i=0;
    while (!str.empty()) {
        i=0;
        tmp="";
        while (str[i] != ',' && i<str.size()) {
            tmp += str[i];
            ++i;
        }
        str.erase(0, i+1);
        if (numbers(tmp[0]) || (tmp.size()>1 && numbers(tmp[1]))) {
            std::stringstream read(tmp);
            double x = 0;
            read >> x;
            number.push(x);
        } else {
            double a, b;
            a = number.pop();
            b = number.pop();
            switch (tmp[0]) {
                case '+':{number.push(a+b); break;}
                case '-':{number.push(b-a); break;}
                case '*':{number.push(a*b); break;}
                case '/':{number.push(b/a); break;}
            }
        }
    }
    return number[0];
}

double Calculate (std::string str){
    return FromPN(ToPN(str));
}
#endif