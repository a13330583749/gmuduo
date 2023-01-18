#include <unistd.h>
#include <thread>
#include <iostream>
#include <syscall.h>
#include <pthread.h>
#include <stdio.h>
//pid: process if ID
//tid: thread of ID

void printID(){
    pthread_t pthread_t_id = pthread_self();   //进程中的线程id
    pid_t threadId = static_cast<pid_t>(::syscall(SYS_gettid)); //真实的线程id唯一标识
    printf("Thread ：PID : %d, TID : %d\n", getpid(), gettid());
    std::thread::id this_is = std::this_thread::get_id();
    std::cout << "pthread_self() = " << pthread_t_id << std::endl;
    std::cout << "::syscall(SYS_gettid) = " << threadId << std::endl;
    std::cout << "std::this_thread::get_id() = " << this_is << std::endl;

}


int main(){
    
    printID(); 
    // pid_t threadId = ::syscall(SYS_gettid);
    
    std::cout << "-----------------------------" << std::endl;
    std::thread t1(printID);
    t1.join();
    

}