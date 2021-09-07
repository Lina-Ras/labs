#ifndef PATTERN_ITERATOR_VISITOR_ITERATOR_MAP_H
#define PATTERN_ITERATOR_VISITOR_ITERATOR_MAP_H
#include <map>
#include <string>

template <typename T>

class Iterator_map {
private:
    std::map<std::string, T> *_map;
    int _size;
    std::string *_all_keys = new std::string [_size];
    int _current;
    bool _empty = true;

    void fill_keys(std::string word){
        int i = 0;
        for(auto it=_map->begin(); it!=_map->end(); ++it){
            if(it->first.find(word) < it->first.size()){
                _all_keys[i] = it->first;
                ++i;
                _empty = false;
            }
        }
        _size = i;
    }

public:

    Iterator_map(std::map<std::string, T> *map, std::string word){
        _map = map;
        _size = map->size();
        fill_keys(word);
        _current = 0;
    }

    ~Iterator_map(){
        delete[] _all_keys;
    }

    T first(){
        _current = 0;
        current_item();
    }

    bool is_done(){
       if( _current == _size-1  ||  _empty)
           return true;
       else
           return false;
   }

   T next(){
        ++_current;
        current_item();
   }

   T current_item(){
       if(!_empty) {
           auto ret = _map->find(_all_keys[_current]);
           return ret->second;
       }
   }
};
#endif