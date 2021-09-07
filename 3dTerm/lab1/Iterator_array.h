#ifndef PATTERN_ITERATOR_VISITOR_ITERATOR_ARRAY_H
#define PATTERN_ITERATOR_VISITOR_ITERATOR_ARRAY_H

template <typename T>

class Iterator_array {
private:
    T *_array;
    int _size;
    int _counter;
public:
    Iterator_array(T *array, int size){
        _size = size;
        _array = array;
        _counter = 0;
    }

    T first(){
        _counter = 0;
        return _array[_counter];
    }

    bool is_done(){
        if( _size - 1 == _counter)
            return true;
        else
            return false;
    }
    T next(){
        if(!is_done())
            _counter++;
        return _array[_counter];
    }

    T current_item(){
        return _array[_counter];
    }

};
#endif
