#include <iostream>
#include <fstream>

using namespace std;


int _strCMP (char *str1, const char *str2){
    int i=0;
    while((str1[i]!='\0')||(str2[i]!='\0')){
        if((str1[i]==str2[i]) && (str1[i+1]=='\0') && (str2[i+1]=='\0')){
            return 0;
        }
        else{
            if(str1[i]>str2[i]) { return 1;}
            else if (str1[i]<str2[i]){return -1;}
        }
        i++;
    }

}

int main() {
    ifstream fin("some.txt");
    char str1[100], str2[100]; //random number of elements
    if (fin.is_open()){
        fin>>str1>>str2;
    }
    fin.close();
    cout<< "_strcmp_ result for str1 and str 2 is " << _strCMP (str1, str2);
    return 0;