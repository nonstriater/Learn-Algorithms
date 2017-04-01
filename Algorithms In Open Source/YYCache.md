
## YYCache

[YYCache](https://github.com/ibireme/YYCache.git) 是 iOS 系统上一套线程安全的 `Key-Value` 缓存实现，使用 `Objective-C` 语言实现。`YYCache` 使用 `双向链表队列+hash表结构` 实现。

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

这里定义了一个双向链表结构，`_prev`,`_next`分别指向前缀节点和后缀节点。

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


