# 链表

* 链表
* 双向链表
* 双向循环链表

## 链表

这个就不介绍了。重点说下双向链表。


### 扩缩容

简单说下编程语言 java， golang中 LinkList的扩缩容的策略。

java 中扩容，每次扩容新增原先容量的 1/2
```
 int newCapacity = oldCapacity + (oldCapacity >> 1);
```


## 双向链表

双向链表也叫双链表，是链表的一种，它的每个数据结点中都有两个指针，分别指向直接后继和直接前驱。所以，从双向链表中的任意一个结点开始，都可以很方便地访问它的前驱结点和后继结点。一般我们都构造双向循环链表。

双向链表克服了单链表中访问某个节点前驱节点(插入，删除操作时)，只能从头遍历的问题。

```
typedef int Value
typedef struct Entry{
	struct Entry *next,*prev;
	Value value;
}DoubleLink;

```

## 循环链表

最后一个节点指针指向头节点的链表


## 双向循环链表








