#include "../IOthread.h"
#include <unistd.h>

void threat(int&& a = 10, IOthread* pIO){
    IOthread IO;
    while(a--){
        ::poll(nullptr, 0, 350);
        std::cout << "a = " << a << std::endl;
    }
    printf("Thread ：PID : %d, TID : %d\n", getpid(), gettid());
    if(getpid() == gettid())
        IO.loop();
}

int main(){
    IOthread IO1;
    
    std::thread IO2(threat, 10);
    IO2.join();
    threat(std::move(9), this);

}