#include "IOthread.h"
#include <exception>
#include <assert.h>

IOthread::IOthread():threadId(std::this_thread::get_id()),
                    looping__(false)
{
    std::cout << "start a IOthread\n";
};

// IOthread::~IOthread() = default;


bool IOthread::assertInIOthread(){
    try{
    if(std::this_thread::get_id() != threadId){
        throw(0);
        return false;
    }
    }
    catch(...){
        std::cout << "you are wrong\n";
    }
    return true;
};

void IOthread::loop(){
    assert(!assertInIOthread());
    assert(!looping__);
    looping__ = true;
    ::poll(nullptr, 0, 1000);
    std::cout << "IOthread " << threadId <<"loop is stop\n";
    looping__ = false;    
}