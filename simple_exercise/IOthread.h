#include <iostream>
#include <memory>
#include <vector>
#include <syscall.h>
#include <thread>
#include "noncopyable.h"
#include <poll.h>

class IOthread: public noncopyable
{
public:
    void loop();
    bool assertInIOthread();
    // bool isInIOthread();
    IOthread();
    ~IOthread() = default;
private:
    const std::thread::id threadId;
    bool looping__;
    //void abortNotInIOthread();
    //std::thread::id this_is = std::this_thread::get_id();
};