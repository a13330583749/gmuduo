每一个Channel对象，只属于一个EventLoop，只属于某一个IO线程
每一个Channel对象只负责一个fd的事件分发，但是并不拥有fd，并不会在析构时关闭fd
Channel对象将不同的IO事件分发为不同的回调
Channel对象的生命期由owner class负责管理
event_是Channel关心的IO事件，由用户设置
revents_是目前活跃的IO事件，由EventLoop/Poller设置
event_、revents_是bit pattern

Channnel::update() => EventLoop::updateChannel() => Poller::updateChannel()

Channel::handleEvent()是Channel的核心