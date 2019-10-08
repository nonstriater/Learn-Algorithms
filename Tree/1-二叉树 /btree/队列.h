//
//  队列.h
//  只在一段进行插入，另一端删除元素
//
//  Created by mac on 13-9-8.
//  Copyright (c) 2013年 xiaoran. All rights reserved.
//

#ifndef DS____h
#define DS____h

#include "public.h"
#include "bintree.c"

typedef BiTNode ElemType;

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
    
    lq->elem = 0;
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
        *e=0;
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
        printf("%d\n",p->elem);
        p=p->next;
    }
    
}



#endif
