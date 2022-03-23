#ifndef CHANNELS_CHANNEL_H
#define CHANNELS_CHANNEL_H

#include <thread>
#include <iostream>
#include <mutex>
#include <queue>
#include <condition_variable>

template<class T>
class BufferedChannel {
private:
    std::mutex m;
    std::queue<T> q;
    std::condition_variable ch;
    int bsize;
    bool closed = false;

    bool is_full(){
        return q.size() == bsize;
    }
public:
    explicit BufferedChannel(int size): bsize(size) {}

    void Send(T value) {
        if(closed){
            throw std::runtime_error("Channel is closed");
        }
        std::unique_lock<std::mutex> lk(m);
        ch.wait(lk, [&](){return !is_full();});
        q.push(value);
        std::cout << "Value " << value << " was added " << '\n';
        lk.unlock();
        ch.notify_all();
    }

    std::pair<T, bool> Recv() {
        std::unique_lock<std::mutex> lk(m);
        ch.wait(lk, [&](){return !q.empty();});
        T ret = q.front();
        q.pop();
        std::cout << "Value " << ret << " was deleted " << '\n';
        lk.unlock();
        ch.notify_one();
        return std::pair<T, bool> (ret, !q.empty());
    }

    void Close() {
        std::lock_guard<std::mutex> lkg(m);
        closed = true;
        ch.notify_one();
    }
};
#endif