
## B树

平衡查找树，一种多路查找树。

能保证数据插入和删除情况下，任然保持执行效率。

一个M阶的B树满足：

1. 每个节点最多M个子节点
2. 除跟节点和叶节点外，其它每个节点至少有M/2个孩子
3. 根节点至少2个节点
4. 所有叶节点在同一层，叶节点不包含任何关键字信息
5. 有k个关键字的页节点包含k+1个孩子

也就是说：`根节点到每个叶节点的路径长度都是相同的。`



## 数据结构


```
typedef struct Item{
     int key;
     Data data;
}

#define m 3 //B树的阶


typedef struct BTNode{
    int degree; //B树的度
    int keynums; //每个节点key的个数
     Item  items[m];
     struct BTNode *p[m];
}BTNode,* BTree;


typedef struct{
     BTNode *pt; //指向找到的节点
     int i; 	// 节点中关键字的序号 (0,m-1)
     int tag; 	//1:查找成功，0：查找失败
}Result;


Status btree_insert(root,target)//插入B树节点
Result btree_find(root,target)//查找B树节点
Status btree_delete(root,target)//删除B树节点
```


## 插入B树节点




## 查找B树节点




## 删除B树节点

















