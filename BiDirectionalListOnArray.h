#ifndef KR2_GR4_PASHKOVETS_ANHELINA_BIDIRECTIONALLISTONARRAY_H
#define KR2_GR4_PASHKOVETS_ANHELINA_BIDIRECTIONALLISTONARRAY_H
#include <iostream>
#include <vector>

template<typename T>
class BiDirectionalListOnArray{
private:
    T *data_;

    size_t size_ = 0;
    size_t capacity_;

    static const size_t MIN_CAPACITY = 10;
    static const size_t GROWTH_FACTOR = 2;

public:
    BiDirectionalListOnArray();
    BiDirectionalListOnArray(const std::initializer_list<T> &st);

    BiDirectionalListOnArray(const BiDirectionalListOnArray &some);
    BiDirectionalListOnArray& operator=(const BiDirectionalListOnArray &other);

    BiDirectionalListOnArray(BiDirectionalListOnArray &&other);
    BiDirectionalListOnArray &operator=(BiDirectionalListOnArray &&other);

    ~BiDirectionalListOnArray();

    int Size();
    bool IsEmpty();

    std::vector<T> ToVector();
    T* Front();
    T* Back();

    void PushFront(const T& value);
    void PushBack(const T& value);

    void PushFront(T&& value);
    void PushBack(T&& value);

    T PopFront();
    T PopBack();

    void InsertBefore(size_t index, const T& value);
    void InsertAfter(size_t index, const T& value);

    void InsertBefore(size_t index, T&& value);
    void InsertAfter(size_t index, T&& value);

    void Erase(size_t index);

    int Find(const T& value);
    std::vector<int> FindAll(const T& value);

    T* operator[] (const int index);
    bool operator== (const BiDirectionalListOnArray<T> &list);
    bool operator!= (const BiDirectionalListOnArray<T> &list);

};

template<typename T>
BiDirectionalListOnArray<T>::BiDirectionalListOnArray(){
    data_ = new T[MIN_CAPACITY];
    capacity_ = 10;
    size_ = 0;
}

template<typename T>
BiDirectionalListOnArray<T>::BiDirectionalListOnArray(const std::initializer_list<T> &st){
    capacity_ = MIN_CAPACITY;
    while (st.size() > capacity_){
        capacity_ *= GROWTH_FACTOR;
    }
    data_ = new T[capacity_];

    size_ = 0;
    for (auto &element : st)
    {
        data_[size_] = element;
        ++size_;
    }
}

template<typename T>
BiDirectionalListOnArray<T>::BiDirectionalListOnArray(const BiDirectionalListOnArray &some):BiDirectionalListOnArray(){
    capacity_ = some.capacity_;
    data_ = new T[capacity_];
    size_ = some.size_;
    for (int i=0; i< size_; ++i){
        data_[i] = some.data_[i];
    }
}

template<typename T>
BiDirectionalListOnArray<T>& BiDirectionalListOnArray<T>::operator=(const BiDirectionalListOnArray &other){
    capacity_ = other.capacity_;
    data_ = new T[capacity_];
    size_ = other.size_;
    for (int i=0; i< size_; ++i){
        data_[i] = other.data_[i];
    }
    return *this;
}

template<typename T>
BiDirectionalListOnArray<T>::BiDirectionalListOnArray(BiDirectionalListOnArray &&other){
    data_ = std::move(other.data_);
    size_ = other.size_;
    capacity_ = other.capacity_;
}

template<typename T>
BiDirectionalListOnArray<T>& BiDirectionalListOnArray<T>::operator=(BiDirectionalListOnArray &&other){
    if (this == &other) {
        return *this;
    }
    data_ = std::move(other.data_);
    size_ = other.size_;
    capacity_ = other.capacity_;
    return *this;
}

template<typename T>
BiDirectionalListOnArray<T>::~BiDirectionalListOnArray(){
    delete [] data_;
}

template<typename T>
int BiDirectionalListOnArray<T>::Size(){
    return size_;
}

template<typename T>
bool BiDirectionalListOnArray<T>::IsEmpty(){
    return size_ == 0;
}

template<typename T>
std::vector<T> BiDirectionalListOnArray<T>::ToVector(){
    if(IsEmpty()){
        throw std::exception();
    }
    std::vector<T> result;
    for (int i=0; i< size_; ++i){
        result.push_back(data_[i]);
    }
    return result;
}

template<typename T>
T* BiDirectionalListOnArray<T>::Front(){
    if(IsEmpty()){
        throw std::exception();
    }
    return &data_[0];
}

template<typename T>
T* BiDirectionalListOnArray<T>::Back(){
    if(IsEmpty()){
        throw std::exception();
    }
    return &data_[size_-1];
}

template<typename T>
void BiDirectionalListOnArray<T>::PushFront(const T& value){
    if(size_ == capacity_){
        capacity_*=GROWTH_FACTOR;
    }
    T* tmp = new T[capacity_];
    *tmp = value;
    for (int i=1; i<=size_; ++i){
        tmp[i] = data_ [i-1];
    }
    ++size_;
    delete [] data_;
    data_ = tmp;
}

template<typename T>
void BiDirectionalListOnArray<T>::PushBack(const T& value){
    if(size_ == capacity_){
        capacity_*=GROWTH_FACTOR;
    }
    T* tmp = new T[capacity_];
    for (int i=0; i<size_; ++i){
        tmp[i] = data_ [i];
    }
    tmp[size_] = value;
    ++size_;
    delete [] data_;
    data_ = tmp;
}

template<typename T>
void BiDirectionalListOnArray<T>::PushFront(T&& value){
    if(size_ == capacity_){
        capacity_*=GROWTH_FACTOR;
    }
    T* tmp = new T[capacity_];
    *tmp = value;
    for (int i=1; i<=size_; ++i){
        tmp[i] = data_ [i-1];
    }
    ++size_;
    delete [] data_;
    data_ = tmp;
}

template<typename T>
void BiDirectionalListOnArray<T>::PushBack(T&& value){
    if(size_ == capacity_){
        capacity_*=GROWTH_FACTOR;
    }
    T* tmp = new T[capacity_];
    for (int i=0; i<size_; ++i){
        tmp[i] = data_ [i];
    }
    tmp[size_] = value;
    ++size_;
    delete [] data_;
    data_ = tmp;
}

template<typename T>
T BiDirectionalListOnArray<T>::PopFront(){
    if(IsEmpty()){
        throw std::exception();
    }
    T* tmp = new T[capacity_];
    T result = data_[0];
    --size_;
    for (int i=0; i<size_; ++i){
        tmp[i] = data_ [i+1];
    }
    delete [] data_;
    data_ = tmp;
    return result;
}

template<typename T>
T BiDirectionalListOnArray<T>::PopBack(){
    if(IsEmpty()){
        throw std::exception();
    }
    --size_;
    return data_[size_];
}

template<typename T>
void BiDirectionalListOnArray<T>::InsertBefore(size_t index, const T& value){
    if (size_<= index || index < 0){
        throw std::exception();
    }
    if(size_ == capacity_){
        capacity_*=GROWTH_FACTOR;
    }
    T* tmp = new T[capacity_];
    for (int i=0; i<index; ++i){
        tmp[i] = data_ [i];
    }
    tmp[index] = value;
    ++size_;
    for (int i=index+1; i<=size_; ++i){
        tmp[i] = data_ [i-1];
    }
    delete [] data_;
    data_ = tmp;
}

template<typename T>
void BiDirectionalListOnArray<T>::InsertAfter(size_t index, const T& value){
    if (size_<= index || index < 0){
        throw std::exception();
    }
    if(size_ == capacity_){
        capacity_*=GROWTH_FACTOR;
    }
    T* tmp = new T[capacity_];
    for (int i=0; i<=index; ++i){
        tmp[i] = data_ [i];
    }
    tmp[index+1] = value;
    ++size_;
    for (int i=index+2; i<=size_; ++i){
        tmp[i] = data_ [i-1];
    }
    delete [] data_;
    data_ = tmp;
}

template<typename T>
void BiDirectionalListOnArray<T>::InsertBefore(size_t index, T&& value){
    if (size_<= index || index < 0){
        throw std::exception();
    }
    if(size_ == capacity_){
        capacity_*=GROWTH_FACTOR;
    }
    T* tmp = new T[capacity_];
    for (int i=0; i<index; ++i){
        tmp[i] = data_ [i];
    }
    tmp[index] = value;
    ++size_;
    for (int i=index+1; i<=size_; ++i){
        tmp[i] = data_ [i-1];
    }
    delete [] data_;
    data_ = tmp;
}

template<typename T>
void BiDirectionalListOnArray<T>::InsertAfter(size_t index, T&& value){
    if (size_<= index || index < 0){
        throw std::exception();
    }
    if(size_ == capacity_){
        capacity_*=GROWTH_FACTOR;
    }
    T* tmp = new T[capacity_];
    for (int i=0; i<=index; ++i){
        tmp[i] = data_ [i];
    }
    tmp[index+1] = value;
    ++size_;
    for (int i=index+2; i<=size_; ++i){
        tmp[i] = data_ [i-1];
    }
    delete [] data_;
    data_ = tmp;
}

template<typename T>
void BiDirectionalListOnArray<T>::Erase(size_t index){
//    if(IsEmpty()){
//        throw std::exception();
//    }
//    if (size_<= index || index < 0){
//        throw std::exception();
//    }
    T* tmp = new T[capacity_];
    for (int i=0; i<index; ++i){
        tmp[i] = data_ [i];
    }
    --size_;
    for (int i=index; i<size_; ++i){
        tmp[i] = data_ [i+1];
    }
    delete [] data_;
    data_ = tmp;
}

template<typename T>
int BiDirectionalListOnArray<T>::Find(const T& value){
    if(IsEmpty()){
        return -1;
    }
    for (int i = 0; i<size_; ++i){
        if(data_[i] == value){
            return i;
        }
    }
    return -1;
}

template<typename T>
std::vector<int>  BiDirectionalListOnArray<T>::FindAll(const T& value){
    std::vector<int> result;
    if(IsEmpty()){
        result.push_back(-1);
        return result;
    }

    for (int i = 0; i<size_; ++i){
        if(data_[i] == value){
            result.push_back(i);
        }
    }
    if(result.empty()){
        result.push_back(-1);
    }
    return result;
}

template <typename T>
T* BiDirectionalListOnArray<T>::operator[] (const int index){
    if(IsEmpty()){
        throw std::exception();
    }
    if (size_<= index || index < 0){
        throw std::exception();
    }
    return &data_[index];
}


template <typename T>
bool BiDirectionalListOnArray<T>::operator== (const BiDirectionalListOnArray<T> &list){
    if (size_ != list.size_){
        return false;
    }
    for (int i=0; i < size_; ++i){
        if(data_[i] != list.data_[i]){
            return false;
        }
    }
    return true;
}

template <typename T>
bool BiDirectionalListOnArray<T>::operator!= (const BiDirectionalListOnArray<T> &list){
    return !(*this == list);
}
#endif