#include <functional>
#include "noncopyable.h"
#include "IOthread.h"
class Channel: public noncopyable{
private:
    IOthread* ptr_iothread_;
    const int fd_;
public:
    using EventLoopCallBack =  std::function<void()>;
    Channel(IOthread* ptr, int fd)

}