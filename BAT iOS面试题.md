


1面问的主要主要知识点。
2面问主要考察的是设计解决方案的能力，另外辅助追问的方式，考察深度和广度，回答过程中需要列出适合的具体例子，方案还需要细致到具体的关键的函数名称，方法。
3面考察设计模式的理解，算法



###UI系统

设计一个progress bar解决方案，追问到 Core Graphic、CGPath、maskLayer。
设计一个popup view被追问到 keyWindow、UIWindow的layer、UIView hierarchy。


CALayer和View的关系  
一个UIView包含CALayer树，CALayer是一个数据模型，包含了一些用于显示的对象，但本身不用于显示。 
CALayer相当于photoshop的一个层，很多动画可以通过设置CALayer来实现。据说有人用CALayer显示图片来播放视频。
Core animation应该是用CAlayer来实现各种动画。
这里有篇博文，介绍的还可以http://www.cnblogs.com/uyoug321/archive/2011/01/22.html 




###消息系统

从设计模式的角度分析Delegate、Notification、KVO的区别。被追问到自己写的library和开源的项目中用到哪些设计模式，为什么使用，有哪些好处和坏处，现在能否改进。


算是问题3的追问，设计一个方案来检测KVO的同步异步问题。willChange和 didChange的不同点，然后被追问到有没有其他地方也有类似情况，被追问到Core Data 中falut object。

这个是问题4的追问，设计一个KVO系统。


###多线程
Multithreading，什么时候采用Multithreading方案，以及理由。追问到系统还有哪些在后台运行的thread，
Multithreading中常常遇到的问题，追问到死锁，优先级翻转，线程池等。



###运行时
Objective C runtime library：这些都需要背后C一层的描述，
Objective C的对象模型，
block的底层实现结构，
消息发送，消息转发，
内存管理
Multithreading：什么时候处理多线程，几种方式，优缺点。

Object c研究的比较深入的教程
http://www.cnblogs.com/yaski/ 第6章写的尤其好

KVO/KVC 实现机理分析
http://archive.cnblogs.com/a/1886332/


###数据处理
Core Data：中多线程中处理大量数据同步时的操作。
缓存设计LRU Cache
sqlite中插入特殊字符的方法和接收到处理方法。


###网络部分
asihttp代码原理 ，异步请求的原理，异步请求最大数目，为什么只能这么多？


叙述TCP/UDP协议，他们的应用，TCP的三次握手，滑动窗口，超时重传;HTTP协议和COOKIE机制和一些COOKIE的问题
 http协议，tcp/ip，TCP/UDP




### 数据结构和算法

 C++里STL的几个库是怎么实现的
（类似：stl有哪些容器？各个容器的区别？以及各容器的数据结构？）
哈希表的遍历时间复杂度
（分析：这个跟hash表的存储结构和hash函数有关）


### 系统设计

设计一个服务器的存储模式
大数据量缓冲服务器的架构设计
手机汉字输入法的架构设计




### 杂谈
简述push原理，push的证书和其它的右什么不一样？
autolayout
core data




内存寻址方式：  
寄存器直接寻址  
基址寻址：方便访问k条记录  
基址+变址寻址：访问一条记录的字段  
  
  

比较32位平台和64位平台不同  
内存寻址空间变大  
基本数据类型的长度也会有些变化（long ，longlong， ptr）  
  
  
iphone app为什么会被打回来，如何避免??  
1） 阅读文档  
2） 看别人被拒的原因，吸取教训  









