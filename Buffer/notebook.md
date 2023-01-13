为什么non-blocking网络编程中应用Buffer是必需的

使用Buffer来建立非阻塞IO的

muduo Eventloop采用的是epoll level trigger，而不是edge trigger，有三个原因：
1.与poll兼容，可以在必要时切换为poll；
2.LT模式更容易编程
3.读写的时候不必等待出现EAGAIN,减少系统调用

在muduo中使用onMessage()回调读取buffer input；调用TcpConnect::send()来间接操作output buffer

muduo Buffer的数据结构`vector<char>`分为三个部分：prependable(前挂)、readble、writable

prepend的作用：程序可以添加一个数据，用来表示某一条消息的长度再发送，例如[../asio]文件的聊天消息会提前说一下有多长