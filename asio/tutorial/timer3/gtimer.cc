#include "muduo/net/EventLoop.h"

#include <iostream>

void print(muduo::net::EventLoop* loop, int count, int* sum)
{
  if (count < 5)
  {
    std::cout << count << "\n";
    ++(count);
    ++(*sum);
    loop->runAfter(1, std::bind(print, loop, count, sum));
  }
  else
  {
    loop->quit(); //这里直接就推出循环了，所以没有那个迭代
  }
}

int main()
{
  muduo::net::EventLoop loop;
  int count = 0;
  int sum = 0;
  // Note: loop.runEvery() is better for this use case.
  loop.runAfter(1, std::bind(print, &loop, count, &sum));
  loop.loop();
  std::cout << "Final sum is " << sum << "\n";
}

