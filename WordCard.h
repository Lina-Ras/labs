#ifndef KR2_GR4_PASHKOVETS_ANHELINA_WORDCARD_H
#define KR2_GR4_PASHKOVETS_ANHELINA_WORDCARD_H
#include <iostream>

using std::string;
class WordCard {
public:
    WordCard();
    WordCard(const string &some);

    WordCard(const WordCard &some);
    WordCard& operator=(const WordCard &other);

    WordCard(WordCard &&other);
    WordCard &operator=(WordCard &&other);

    ~WordCard() = default;

    string GetWord();
    size_t GetCounter();

    void IncCounter();

    bool operator==(const WordCard &other);
    bool operator!=(const WordCard &other);

    bool operator<(const WordCard &other);

private:
    string word_;
    size_t counter_;
};

WordCard::WordCard(){
    word_ = "";
    counter_ = 0;
}

WordCard::WordCard(const string &some){
    word_ = some;
    counter_ = 1;
}

WordCard::WordCard(const WordCard &some){
    word_ = some.word_;
    counter_ = some.counter_;
}

WordCard& WordCard::operator=(const WordCard &other){
    this->word_ = other.word_;
    this->counter_ = other.counter_;
}

WordCard::WordCard(WordCard &&other){
    word_ = std::move(other.word_);
    counter_ = other.counter_;
}

WordCard& WordCard::operator=(WordCard &&other){
    if (this == &other) {
        return *this;
    }
    word_ = std::move(other.word_);
    counter_ = other.counter_;
    return *this;
}

string WordCard::GetWord(){
    return this->word_;
}

size_t WordCard::GetCounter(){
    return this->counter_;
}

void WordCard::IncCounter(){
    ++this->counter_;
}

bool WordCard::operator==(const WordCard &other){
    return this->word_ == other.word_;
}

bool WordCard::operator!=(const WordCard &other){
    return this->word_ != other.word_;
}

bool WordCard::operator<(const WordCard &other){
    return this->word_ < other.word_;
}
#endif
