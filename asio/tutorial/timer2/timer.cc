#include "muduo/net/EventLoop.h"

#include <iostream>

//非阻塞定时，定时和IO在同一个线程中
void print()
{
  std::cout << "Hello, world!\n";
}

int main()
{
  muduo::net::EventLoop loop;
  loop.runAfter(5, print);
  loop.loop();
}

