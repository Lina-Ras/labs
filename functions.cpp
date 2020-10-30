#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include "functions.h"

std::string ConsoleReader(std::string msg) {
    std::string tmp;
    std::cout << "Enter string " << msg << ": ";
    std::cin>>tmp;
    return tmp;
}

std::vector<std::string>FileReader(std::string input_file){
    std::vector<std::string> vec;
    std::ifstream fin(input_file+".txt");
    std::string line;
    while(!fin.eof()) {
        std::getline(fin, line, '\n');
        vec.push_back(line);
    }
    fin.close();
    return vec;
}

std::vector<std::string>WordParser(std::vector<std::string> lines){
    std::vector<std::string> vec;
    std::string line;
    for (int i=0; i< lines.size(); ++i) {
        int k=0;
        while (k<lines[i].size()) {
            while(lines[i][k]!=' ' && lines[i][k]!='\000' && lines[i][k]!='\t'){
                line+=lines[i][k];
                k++;
            }
            if(line!="") {
                vec.push_back(line);
            }
            line="";
            while(lines[i][k]==' ') {
                k++;
            }
        }
    }
    return vec;
}

void ConsoleOutput(std::vector<std::string> &vec){
    for(int i=0; i<vec.size(); ++i) {
        std::cout << vec[i]<<'\n';
    }
    std::cout<<'\n';
}

void Encryption (std::string file_path, unsigned char key){
    std::vector<std::string> text;
    text = FileReader(file_path);
    text = WordParser(text);
    std::vector<std::string>new_text=text;
    std::ofstream fout(file_path+"_encr.txt");

    bool flag(false);
    for(int i=0; i < text.size(); ++i){
        for(int k=0; k < text[i].size(); ++k){
            new_text[i][k] = text[i][k] ^ key;
        }

        fout.width(10);
        fout << new_text[i];
        if(flag){
            fout<<'\n';
            flag=false;
        }
        else{
            flag=true;
        }
    }
    fout.close();
}



bool IsNotDecreasingOrder(std::string str){
    bool flag(true);
    int i = 1;
    while(flag && (i + 2) < str.size()){
        flag=false;
        if(str[i]>=str[i+2]){
            flag=true;}
        i+=2;
    }
    return flag;
}

std::vector<std::string> FindItems(std::vector<std::string> str){
    std::vector<std::string> collection;
    for (int i=0; i< str.size(); ++i) {
        if(IsNotDecreasingOrder(str[i])){
            collection.push_back(str[i]);
        }
    }
    return collection;
}


int WordWeight (std::string str){
    int weight=0;
    for (int i=0; i< str.size(); ++i) {
        int a=str[i];
        int b=str[i];
        a = a >> 1;
        b = b >> 3;
        if(a%2==1 && b%2==1){
            weight+=str[i];
        }
    }
    return weight;
}

int WordWeight (std::vector<std::string> str){
    int weight=0;
    for (int k=0; k< str.size(); ++k) {
        for (int i = 0; i < str[k].size(); ++i) {
            int a = str[k][i];
            int b = str[k][i];
            a = a >> 1;
            b = b >> 3;
            if (a % 2 == 1 && b % 2 == 1) {
                weight += str[k][i];
            }
        }
    }
    return weight;
}

std::map<std::string, int> Weight_map(std::vector<std::string> words)
{
    std::map<std::string, int> weight;
    auto it = weight.begin();
    for (int i=0; i< words.size(); ++i) {
        weight.insert ( std::pair<std::string,int>(words[i],WordWeight(words[i])) );
    }
    return weight;
}

void SortCollection(std::vector<std::string> vec){
    sort(vec.begin(), vec.end(), [](std::string a, std::string b){return WordWeight(a)<WordWeight(b);});
}


