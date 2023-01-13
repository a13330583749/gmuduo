#include "muduo/net/EventLoop.h"
#include "muduo/base/Thread.h"

#include <assert.h>
#include <stdio.h>
#include <unistd.h>

using namespace muduo;
using namespace muduo::net;

EventLoop* g_loop;

void callback()
{
  printf("callback(): pid = %d, tid = %d\n", getpid(), CurrentThread::tid());
  //EventLoop anotherLoop;
}

void threadFunc()
{
  printf("threadFunc(): pid = %d, tid = %d\n", getpid(), CurrentThread::tid());

  assert(EventLoop::getEventLoopOfCurrentThread() == NULL);
  EventLoop loop;
  assert(EventLoop::getEventLoopOfCurrentThread() == &loop);
  loop.runAfter(1.0, callback);
  loop.loop(); 
}

void threadFunc2(EventLoop* p)
{
  printf("threadFunc2(): pid = %d, tid = %d\n", getpid(), CurrentThread::tid());

  assert(EventLoop::getEventLoopOfCurrentThread() == NULL);
  //EventLoop loop;
  //assert(EventLoop::getEventLoopOfCurrentThread() == p);
  printf("pass assert\n");
  p->runAfter(1.0, callback);
  // printf("pass runAfter\n");
  // p->loop();//这里会报错，由于这个EventLoop不是在创建线程中运行
}

int main()
{
  // 一个线程只可以存在一个EventLoop对象
  // EventLoop t1;
  // EventLoop t2;
  printf("main(): pid = %d, tid = %d\n", getpid(), CurrentThread::tid());
  assert(EventLoop::getEventLoopOfCurrentThread() == NULL);
  EventLoop loop;  
  assert(EventLoop::getEventLoopOfCurrentThread() == &loop);

  //Thread thread(threadFunc);
  Thread thread2(std::bind(threadFunc2, &loop));
  thread2.start();
  //thread.join();
  //printf("main() will be start\n");
  sleep(10);
  loop.quit();

}
