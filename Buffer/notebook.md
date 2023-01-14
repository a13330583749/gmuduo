为什么non-blocking网络编程中应用Buffer是必需的

使用Buffer来建立非阻塞IO的

muduo Eventloop采用的是epoll level trigger，而不是edge trigger，有三个原因：
1.与poll兼容，可以在必要时切换为poll；
2.LT模式更容易编程
3.读写的时候不必等待出现EAGAIN,减少系统调用

在muduo中使用onMessage()回调读取buffer input；调用TcpConnect::send()来间接操作output buffer

muduo Buffer的数据结构`vector<char>`分为三个部分：prependable(前挂)、readble、writable

prepend的作用：程序可以添加一个数据，用来表示某一条消息的长度再发送，例如[../asio]文件的聊天消息会提前说一下有多长

Protobuf 有如 XML，不过它更小、更快、也更简单。你可以定义自己的数据结构，然后使用代码生成器生成的代码来读写这个数据结构。你甚至可以在无需重新部署程序的情况下更新数据结构。

编解码器（codec）的设计，encoder和decoder的缩写，在网络编程中，指“把网络数据和业务消息之间相互转化”的代码。
在简单的网络编程中，没有消息，只有字节流

non-trival的网络服务以消息为单位进行通讯
需要对发送和接受的消息进行压缩、解包。

为什么需要codec?
    在non-blocking网络中，由于TCP分包，如果只接收到半条消息，则需要在Buffer中等待，等待一个完整的消息到达再进行处理，因此有了`utility class`，

在asio中，codec作为TcpConnection和ChatServer之间的简介层

xian