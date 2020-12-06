#ifndef KR2_GR4_PASHKOVETS_ANHELINA_VOCABULARY_H
#define KR2_GR4_PASHKOVETS_ANHELINA_VOCABULARY_H
#include <iostream>
#include "WordCard.h"
#include "BiDirectionalListOnArray.h"
#include "FileReader.h"
#include <map>

class Vocabulary {
public:
    void read_file_to_cards(std::string file_path);
    WordCard* convert_string_to_word_card(std::string &str);
    void make_frequency_vocab();
    void sort_words(); // можно пузырьком 😊  ок!
    std::map<string, size_t> copy_to_map();

private:
    BiDirectionalListOnArray <WordCard*> list_word_cards;
};

void Vocabulary::read_file_to_cards(std::string file_path){
    std::string tmp;
    std::ifstream fin(file_path);
    if (fin.is_open()){
        while (!fin.eof()){
            std::getline(fin, tmp, ' ');
            this->list_word_cards.PushBack(convert_string_to_word_card(tmp));
        }
    }
    fin.close();
}

WordCard* Vocabulary::convert_string_to_word_card(std::string &str){
    WordCard* result = new WordCard(str);
    return result;
}

void Vocabulary::make_frequency_vocab(){
    int i=0;
    while (i<list_word_cards.Size()){
        int j=i+1;
        while (j<list_word_cards.Size()){
            if(**list_word_cards[i] == **list_word_cards[j]){
                list_word_cards.Erase(j);
                (**list_word_cards[i]).IncCounter();
            }
            ++j;
        }
        ++i;
    }
}

void Vocabulary::sort_words(){
    for (int i = 0; i+1 < list_word_cards.Size(); ++i){
        for (int j = 0; j+1 < list_word_cards.Size() - i; ++j){
            if (**list_word_cards[j+1] < **list_word_cards[j]) {
                std::swap(**list_word_cards[j+1], **list_word_cards[j]);
            }
        }
    }
}

std::map<string, size_t> Vocabulary::copy_to_map(){
    std::map<string, size_t> result;
    for(int i=0; i< list_word_cards.Size(); ++i) {
        result.insert(std::pair<string, size_t>((**list_word_cards[i]).GetWord(), (**list_word_cards[i]).GetCounter()));
    }
    return result;
}
#endif
