#pragma once
#include <fstream>

std::string ConsoleReader(std::string msg);
std::vector<std::string>FileReader(std::string input_file);
std::vector<std::string>WordParser(std::vector<std::string> lines);

void ConsoleOutput(std::vector<std::string> &vec);
void Encryption (std::string file_path, unsigned char key);
template <typename T>
void FileWriter(std::map<std::string, T> some) {
    std::ofstream fout("output_file.txt");

    for (auto i = some.begin(); i != some.end(); ++i)
    {
        fout.width(10);
        fout << i->first;
        fout.width(10);
        fout << i->second << '\n';
    }
    fout.close();
}


bool IsNotDecreasingOrder(std::string str);
std::vector<std::string> FindItems(std::vector<std::string> str);

int WordWeight (std::string str);
int WordWeight (std::vector<std::string> str);
std::map<std::string, int> Weight_map(std::vector<std::string> words);
void SortCollection(std::vector<std::string>);

