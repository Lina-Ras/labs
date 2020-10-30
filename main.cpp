#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "functions.h"


int main() {
    std::cout << "1 Task \n";
    std::string str;
    str=ConsoleReader("str");
    if(IsNotDecreasingOrder(str)){
        std::cout << "true\n";
    } else{
        std::cout << "false\n";
    }
    std::cout << "Task 1 is complete!\n";


    std::cout << "2 Task \n";
    std::string input_file;
    std::vector<std::string> lines;
    input_file=ConsoleReader("name of input file");
    lines=FileReader(input_file);
    std::cout << "Task 2 is complete!\n";

    std::cout << "3 Task \n";
    std::vector<std::string> words;
    words = WordParser(lines);
    std::cout << "Task 3 is complete!\n";

    std::cout << " Task 4\n";
    std::vector<std::string> words_collection;
    words_collection= FindItems(words);
    std::cout << "Task 4 is complete!\n";

    std::cout << " Task 5\n";
    int weight;
    weight=WordWeight("1J3");
    std::cout << "Task 5 is complete!\n";

    std::cout << " Task 6\n";
    std::map<std::string, int> word_weight_map;
    word_weight_map=Weight_map(words_collection);
    FileWriter(word_weight_map);
    std::cout << "Task 6 is complete!\n";


    std::cout << " Task 7\n";
    SortCollection(words_collection);
    std::cout << "Task 7 is complete!\n";

    std::cout << " Task 8\n";
    /*std::map<std::string, unsigned int> some_map = {{ "First", 2 },
                                                    { "Second", 1 },
                                                     { "hv", 3 }};
    FileWriter(some_map); */
    std::cout << "Task 8 is complete!\n";

    std::cout << " Task 9\n";
    int weightVec;
    weightVec=WordWeight(words_collection);
    std::cout << "Task 9 is complete!\n";

    std::cout << " Task 10\n";
    Encryption("output_file", 'y');
    Encryption("output_file_encr", 'y');
    std::cout << "Task 10 is complete!\n";

    std::cout << "All tasks are complete!\n";
    return 0;
}
