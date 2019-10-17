/**
*  	第一次题目	：构建二叉树(链表存储方式)，空格表示空树，实现二叉树的基本操作:创建，遍历（先，中，后，按层）二叉树
*  	提交邮箱 		：510495266@qq.com   to  learn_algorithm@163.com
*  	邮件题目		：第一期第一次作业
**/

#include <stdlib.h>
#include <stdio.h>


typedef struct BiTNode{

	char item;
	struct BiTNode *lChild,*rChild;

}BiTNode,*BiTree;





// ==========================================================================


#define OK 1
#define ERROR 0
typedef int bool;


typedef BiTree ElemType ; // 也可能是一个复杂的复合类型
typedef int Status;



//队列的顺序存储
typedef struct Node{
    
    ElemType *elem;
    ElemType *head;
    ElemType *tail;
    int length;   // 当前队列的长度
    int size;     // 队列容器的长度，在队列慢得时候可以扩容
    

}SqQueue;

//
// 在队列采用顺序存储时，有一个毛病，就是队列操作一段时间后，头指针到了队列容器的尾部，而头指针前面的容器内存不可用了，
//造成内存极大的浪费，这个问题可以通过循环队列来解决。但是在
// 链式队列上则不存在这样的问题
//


typedef struct QNode{
    
    struct QNode *next;
    ElemType elem;
    
}LinkQueue;


// 队列需要维护两个 指针 （队头指针，队尾指针）

typedef struct{
    
    LinkQueue *head;
    LinkQueue *tail;
    int length;

}Queue;


Status initQueue(Queue *queue);// 带头结点,没有引用传值，就用指针的指针吧
bool isEmpty(Queue *q);
int length(Queue *q);


// 在头部插入，尾部删除
Status getHead(Queue *q,ElemType *e);
Status enQueue(Queue *q,ElemType e);
Status deQueue(Queue *q,ElemType *e);

void traveser(Queue *q);


Status initQueue(Queue *queue){// 带头结点,没有引用传值，就用指针的指针吧

    LinkQueue *lq = (LinkQueue *)malloc(sizeof(LinkQueue));
    if (!lq) {
        return ERROR;
    }
    
    lq->elem = NULL;
    lq->next = NULL;
    
    (queue)->head = (queue)->tail = lq; // -> 优先级高于 * ,老老实实打上括号
    (queue)->length = 0;

    return OK;
    
}

bool isEmpty(Queue *q){

    return (q->head == q->tail);
    
}

int length(Queue *q){
    
//    int ret;
//    LinkQueue *p = q->head;
//    while (p != q->tail) {
//        ret++;
//        p = p->next;
//        
//    }
    
    return q->length;

}

Status getHead(Queue *q,ElemType *e){
    
    LinkQueue *p = q->head->next;
    if (!p) {
       	*e=NULL;
        return ERROR;
    }
    
    *e = p->elem;
    return OK;
    
}

// 入队(加入到队尾)
Status enQueue(Queue *q,ElemType e){

    LinkQueue *newNode = (LinkQueue *)malloc(sizeof(LinkQueue));
    if (!newNode) {
        return ERROR;
    }
    newNode->elem = e;
    newNode->next = NULL;
    q->tail->next = newNode;
    q->tail = newNode;
    
    q->length++;
    
    return OK;
    
}

//出队（队头）. 注意，可能只有1个元素，造成队尾指针丢失
Status deQueue(Queue *q,ElemType *e){

    LinkQueue *p = q->head->next;
    if (!p) {// 队列空
        return ERROR;
    }
    
    if (e) {
         *e = p->elem ;
    }
   
    LinkQueue *temp = p->next;
    q->head->next = temp;
    if (p == q->tail) {
        q->tail = q->head;
    }
    free(p);
    
    
    q->length--;
    
    return OK;
    
}


void traveser(Queue *q){
    
    LinkQueue *p = q->head->next;
    while (NULL != p) {
        //printf("%d\n",p->elem);
        p=p->next;
    }
    
}


// ==================================================



/*
int CreateBiTree(BiTree *T)
{

	*T = (BiTNode *)malloc(sizeof(BiTNode));
	if (*T==NULL)
	{
		printf("memery malloc failure !\n");
		return -1;
	}

	printf("enter data to create node:\n");
	scanf("%c",&((*T)->item));
	if((*T)->item=='#'){
		*T=NULL;
	} 
	if(*T){
		printf("创建左子树:\n");
		CreateBiTree( &((*T)->lChild) );
		printf("创建右子树:\n");
		CreateBiTree( &((*T)->rChild) );
	}

	return 0;
}
*/

// BiTree CreateBiTree()

// 先序遍历方式创建二叉树
BiTree CreateBiTree(){

	char c;
	BiTNode *tree;

	// 过滤回车键


	scanf("%c",&c);
	if (c==' ')
	{
		printf("创建空节点\n");
		tree = NULL;
	}else{
		printf("创建节点 %c\n",c);
		tree = (BiTNode *)malloc(sizeof(BiTNode));
		tree->item = c;
		tree->lChild = CreateBiTree();
		tree->rChild = CreateBiTree();
	}

	return tree;

}


int PreOrderTraverse(BiTree T){

	if(T){
		printf("%c\n",T->item );
		PreOrderTraverse(T->lChild);
		PreOrderTraverse(T->rChild);
	}

	return 0;
}

int InOrderTraverse(BiTree T){

	if (T)
	{
		InOrderTraverse(T->lChild);
		printf("%c\n", T->item);
		InOrderTraverse(T->rChild);
	}

	return 0;
}

int PostOrderTraverse(BiTree T){

	if (T)
	{
		PostOrderTraverse(T->lChild);
		PostOrderTraverse(T->rChild);
		printf("%c\n",T->item );
	}

	return 0;
}

// 广度优先遍历 （队列实现）
int LevelOrderTraverse(BiTree T){

	if (T)
	{
		Queue queue;
		initQueue(&queue);

		BiTree u;   
    	u=(BiTree)malloc(sizeof(BiTNode));   
   		enQueue(&queue, T);   
     	 while(!isEmpty(&queue))   
		{    
       		 deQueue(&queue, &u);   
        	 printf("%c",u->item);   
			if(u->lChild)   
    			enQueue(&queue, u->lChild);   
			if(u->rChild)   
       			enQueue(&queue, u->rChild);   
		}  
	} 

	return 0;
}



 int main(int argc, char const *argv[])
{
	/* code */
	BiTree binaryTree;

	printf("创建二叉树，输入\"空格\"创建空节点（先序方式建立二叉树）:\n");
	binaryTree =  CreateBiTree();
	if(binaryTree==NULL){
		printf("创建空的二叉树\n");
	}


	printf("前序遍历:\n");
	PreOrderTraverse(binaryTree);
	printf("\n\n");

	printf("中序遍历:\n");
	InOrderTraverse(binaryTree);
	printf("\n\n");

	printf("后序遍历:\n");
	PostOrderTraverse(binaryTree);
	printf("\n\n");

	printf("层序遍历:\n");
	LevelOrderTraverse(binaryTree);
	printf("\n\n");


	return 0;
}





