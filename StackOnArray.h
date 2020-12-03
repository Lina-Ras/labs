#ifndef STACKONARRAY_STACKONARRAY_H
#define STACKONARRAY_STACKONARRAY_H

template <typename T>
class StackOnArray {
public:
    StackOnArray(){
        _top = -1;
        _stack = new T[_capacity];
    }

    ~StackOnArray(){
        delete [] _stack;
    }

    bool isEmpty();

    void push(T value);
    T pop();
    T top();

    void operator>> (T &last);
    void operator<< (T value);
    T& operator[] (const int index);

    StackOnArray& operator= (const StackOnArray<T> &stack);
    bool operator== (const StackOnArray<T> &stack);
    bool operator< (const StackOnArray<T> &stack);

private:
    void extendCapacity();

    T* _stack;
    int _top;
    int _capacity = 100;
};

template <typename T>
bool StackOnArray<T>::isEmpty(){
    if (_top == -1){
        return true;
    } else
        return false;
}

template <typename T>
T& StackOnArray<T>::operator[] (const int index){
    if (index <= _top  && index>-1)
        return _stack[index];
    else
        throw ("Out of range");
}

template <typename T>
void StackOnArray<T>::push(T value){
    if (_top+1 == _capacity){
        extendCapacity();
    }
    _stack[++_top] = value;
}

template <typename T>
T StackOnArray<T>::pop(){
    if (!isEmpty()) {
        return _stack[_top--];
    } else{
        throw ("Stack is empty!");
    }
}

template <typename T>
T StackOnArray<T>::top(){
    if (!isEmpty()) {
        return _stack[_top-1];
    } else{
        throw ("Stack is empty!");
    }
}

template <typename T>
void StackOnArray<T>::operator>> (T &last){
    last = pop();
}

template <typename T>
void StackOnArray<T>::extendCapacity(){
    T* stack = new T[_capacity*2];
    _capacity*=2;
    for (int i=0; i<=_top; ++i){
        stack[i] = _stack[i];
    }
    delete [] _stack;
    _stack = stack;
}

template <typename T>
void StackOnArray<T>::operator<< (T value){
    push(value);
}

template <typename T>
StackOnArray<T>& StackOnArray<T>::operator= (const StackOnArray<T> &stack){
    _capacity = stack._capacity;
    _top = stack._top;
    for(int i=0; i<= _top; ++i){
        _stack[i] = stack._stack[i];
    }
    return *this;
}

template <typename T>
bool StackOnArray<T>::operator== (const StackOnArray<T> &stack){
    return _top==stack._top;
}

template <typename T>
bool StackOnArray<T>::operator< (const StackOnArray<T> &stack){
    return _top<stack._top;
}
#endif
