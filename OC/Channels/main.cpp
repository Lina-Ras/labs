#include <iostream>
#include <thread>
#include <vector>
#include "buffered_channel.h"

int n = 9;
BufferedChannel<int> test(n);

void add(int val){
    test.Send(val);
}

std::pair<int, bool> pop(){
    return test.Recv();
}

int main() {
    std::vector<std::thread> th1;
    for(int i=0; i<14; ++i){
        th1.emplace_back(std::thread(add, i));
    }
    for(int i=0; i<10; ++i){
        th1.emplace_back(std::thread(pop));
    }
    test.Close();
    std::cout << "delete" << '\n';
    std::cout << test.Recv().first << test.Recv().second;
    test.Recv();
    test.Recv();
    test.Recv();
    test.Recv();
    test.Recv();
    for(auto& t : th1){
        t.join();
    }
    return 0;
}
