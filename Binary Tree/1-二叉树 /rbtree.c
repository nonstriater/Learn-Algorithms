/*
### 红黑树基础

一种自平衡的二叉查找树。在每个节点中增加一个存储位表示节点的颜色，可以是red或black

红黑树比AVL树优秀在哪？





5个性质

性质1. 节点是红色或黑色。
性质2. 根是黑色。
性质3. 所有叶子都是黑色（叶子是NIL节点）。
性质4. 每个红色节点的两个子节点都是黑色。(从每个叶子到根的所有路径上不能有两个连续的红色节点)
性质5. 从任一节点到其每个叶子的所有简单路径 都包含相同数目的黑色节点。



### 红黑树应用


### 存储结构


### 问题与延伸阅读


*/

typedef int ElemType 

typedef struct node{

	int color;
	ElemType key;
	struct node *lChild,*rChild,*pChild;

}*RBTree;


int rbtree_insert(RBTree *tree,ElemType key);
int rbtree_remove(RBTree *tree,ElemType key);
int rbtree_search(RBTree *tree,ElemType key);



