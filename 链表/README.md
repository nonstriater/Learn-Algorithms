
## 链表

* 链表
* 双向链表

### 链表

这个就不介绍了。重点说下双向链表。


### 双向链表

双向链表也叫双链表，是链表的一种，它的每个数据结点中都有两个指针，分别指向直接后继和直接前驱。所以，从双向链表中的任意一个结点开始，都可以很方便地访问它的前驱结点和后继结点。一般我们都构造双向循环链表。

双向链表克服了单链表中访问某个节点前驱节点(插入，删除操作时)，只能从头遍历的问题。

```
typedef int Value
typedef struct Entry{
	struct Entry *next,prev;
	Value value;
}DoubleLink;

```

### 带哨兵的双向链表

取自Nginx 源码 中 ngx_queue_t 的使用：
```
struct ngx_queue_s {
	ngx_queue_t * prev;
	ngx_queue_t * prev;
} ngx_queue_t;
```

首先定义，并且初始化一个哨兵节点
```
ngx_queue_t sentry;
ngx_queue_init(&sentry);
```
定义自己的结构体:
```
struct my_node_t {
	int a;
	char b;
	void c;
	// 加入queue节点
	ngx_queue_t queue;
};
```
#### 插入 
```
//头部插入
int insert_head(h,x) {
	(x)->next = (h)->next;
	(x)->next->prev = x;
	(x)->prev = h;
	(h)->next = x;
}

//尾部插入
int insert_tail(h,x) {
	(x)->prev = (h)->prev;
	(x)->prev->next = x;
	(x)->next = h;
	(h)->prev = x;
}
```

用法:
```
my_node_t x,y;
insert_head(&sentry,&x);
insert_tail(&sentry,&y);
```
PS:保持哨兵节点的 prev 指向链表的尾数据节点，next 指向链表的头数据节点









