#ifndef KR2_GR4_PASHKOVETS_ANHELINA_FILEREADER_H
#define KR2_GR4_PASHKOVETS_ANHELINA_FILEREADER_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class FileReader {
public:
    std::vector<std::string> ReadLines(const std::string &file_path){
        std::vector<std::string> result;
        std::string tmp;
        std::ifstream fin(file_path);
        if (fin.is_open()){
            while (!fin.eof()){
                std::getline(fin, tmp, '\n');
                result.push_back(tmp);
            }
        }
        return result;
    }

    std::vector<std::string> ReadWords(const std::string &file_path) {
        std::vector<std::string> result;
        std::string tmp;
        std::ifstream fin(file_path);
        if (fin.is_open()){
            while (!fin.eof()){
                std::getline(fin, tmp, ' ');
                result.push_back(tmp);
            }
        }
        return result;
    }
};

#endif
