
## 开源项目中用到的算法

数据结构往往是一个项目系统的核心，理解项目的数据结构和算法，才能真正理解项目的工作原理。这里聊聊常用`开源项目`中用到的数据结构和算法。


每一条说清楚：

1. 项目简介  
2. 用到的算法介绍  

## [YYCache](https://github.com/ibireme/YYCache.git)

### 项目简介

YYCache 是iOS系统上一套线程安全的Key-Value缓存实现，使用Objective-C语言实现。YYCache使用双向链表队列+hash表结构实现。

### 用到的算法介绍 

先来看一下它的数据结构：

```
// 这是一个节点的结构
@interface _YYLinkedMapNode : NSObject {
    @package
    __unsafe_unretained _YYLinkedMapNode *_prev; // retained by dic
    __unsafe_unretained _YYLinkedMapNode *_next; // retained by dic
    id _key;
    id _value;
    NSUInteger _cost;
    NSTimeInterval _time;
}
```

这里定义了一个双向链表结构，_prev,_next分别指向前缀节点和后缀节点。

```
@interface _YYLinkedMap : NSObject {
    @package
    CFMutableDictionaryRef _dic; // do not set object directly
    NSUInteger _totalCost;
    NSUInteger _totalCount;
    _YYLinkedMapNode *_head; // MRU, do not change it directly
    _YYLinkedMapNode *_tail; // LRU, do not change it directly
    BOOL _releaseOnMainThread;
    BOOL _releaseAsynchronously;
}
```
_dic 就是存储缓存节点的hash结构  
_head 指向链表的头部，_tail指向链表的尾部，组成一个队列结构

## [cocos2d-objc](https://github.com/cocos2d/cocos2d-objc)

### 项目简介


### 用到的算法介绍 



## [AsyncDisplayKit](https://github.com/facebook/AsyncDisplayKit)

### 项目简介


### 用到的算法介绍 


## [realm-cocoa](https://github.com/realm/realm-cocoa)



## [YapDatabase](https://github.com/yapstudios/YapDatabase)



## [FTCoreText](https://github.com/Ridiculous-Innovations/FTCoreText)


## [Redis](https://github.com/antirez/redis)



## [memcached](https://github.com/memcached/memcached)



## [Nginx](https://github.com/nginx/nginx)



## [Node](https://github.com/nodejs/node)

V8引擎

## [React](https://github.com/facebook/react)


## [react-native](https://github.com/facebook/react-native)







