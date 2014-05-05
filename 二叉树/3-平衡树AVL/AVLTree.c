
/*
自平衡二叉查找树（AVL tree）: 首先也是二次查找树，其实 任何2个子树的高度差不大于1
在删除，插入的过程中不断调整子树的高度，保证平均和最坏情况下都是O(logn)

Adelson-Velskii 和 Landis 1962年 创造。

1） 平衡因子 -1 0 1 节点是正常的。平衡因子 = 左子树高度-右字数高度
2） 除此之外的节点是不平衡的，需要重新平衡这个树。也就是AVL旋转

插入节点：

a: 左旋转(RR型：节点x的右孩子的右孩子上插入新元素）平衡因子由-1 -》-2 时，需要绕节点x左旋转
b：右旋转(LL型：节点X的左孩子的左孩子上插入新元素） 平衡因子有1-》2，右旋转
c: 先左后右旋转:(LR型:树中节点X的左孩子的右孩子上插入新元素） 平衡因子从1变成2后，就需要 先绕X的左子节点Y左旋转，接着再绕X右旋转
d: 先右后左旋转：(RL型:节点X的右孩子的左孩子上插入新元素) 


		6	  6                  6              6           
	   /		\           	/                \
	  5          7	           3                  9
	/          	  \             \                 /
   3               8             5               7
    (LL型)     （RR）            (LR)            (RL)    


删除节点：




可以看到，为了保证高度平衡，插入和删除操作代价增加

记于2014-2-28  by @nonstriater 
*/

#include <stdio.h>
#include <stdlib.h>


#define LH 1
#define EH 0
#define RH -1


typedef int KEY_TYPE;
typedef struct node{

	KEY_TYPE 	key;
	int 		height; // 平衡因子
	struct node *lChild;
	struct node *rChild;

}AVLTree;



//
void avltree_rr_rotate(AVLTree **tree){

	AVLTree *right= *tree->rChild;
	right->lChild = *tree;
	*tree->rChild = right->lChild;

}

//
void avltree_ll_rotate(AVLTree **tree){

	AVLTree *left = *tree->lChild;
	left->rChild = *tree;
	*tree->lChild = left->rChild
}

//
void avltree_lr_rotate(AVLTree **tree){


}

void avltree_rl_rotate(AVLTree **tree){


}


void avltree_left_balance(AVLTree **root)
{
    AVLTree *left,*lr;
    left=(*root)->lChild;
    switch(left->height)
    {
        //检查T的左子树平衡度，并作相应的平衡处理
        case LH://新节点插入在T的左孩子的左子树上，做单右旋处理
            (*root)->height=left->height=EH;
            avltree_ll_rotate(root);
            break;
        case RH://新插入节点在T的左孩子的右子树上，做双旋处理
            lr=left->rChild;
            switch(lr->height)
            {
                case LH:
                    (*root)->height=RH;
                    left->height=EH;
                    break;
                case EH:
                    (*root)->height=left->height=EH;
                    break;
                case RH:
                    (*root)->height=EH;
                    left->height=LH;
                    break;
            }
            lr->height=EH;
            L_Rotate(&(*T)->lChild);
            R_Rotate(T);
    }
}


void avltree_right_balance(AVLTree **root)
{
    AVLTree right,rl;
    right=(*root)->rChild;
    switch(right->height)
    {
        case RH://新节点插在T的右孩子的右子树上，要做单左旋处理
            (*root)->height=right->height=EH;
            avltree_rr_rotate(root);
            break;
        case LH://新节点插在T的右孩子的左子树上，要做双旋处理
            rl=right->lChild;
            switch(rl->height)
            {
                case LH:
                    (*root)->height=EH;
                    right->height=RH;
                    break;
                case EH:
                    (*root)->height=right->height=EH;
                    break;
                case RH:
                    (*root)->height=LH;
                    right->height=EH;
                    break;
            }
            rl->height=EH;
            R_Rotate(&(*root)->rChild);
            L_Rotate(T);
    }
}




// 插入一个节点key
/*

算法描述：
1）如果root为null，则插入一个数据元素为kx 的新结点作为T 的根结点

2）如果key和root->key相等，不插入

3）如果key<root->key, 插在root左子树上：




*/
AVLTree* avltree_insert(AVLTree* root, KEY_TYPE key){


	if (NULL==root)
	{

		root = (AVLTree *)malloc(sizeof(struct AVLTree));
		if (!root)
		{
			printf("内存分配失败,插入节点失败\n");
			return root;
		}
		root.key = key;
		root.lChild = NULL;
		root.rChild = NULL;
		root.height = 0;	
	}

	
	else if (key=root->key)
	{
		printf("节点 %d 已存在 \n", key);
	}

	else if (key<root->key)//插入左
	{
		root->lChild = avltree_insert(root->lChild,key);
		if (root->lChild->height-root->rChild->height == 2)//不平衡
		{
			if (key<root->lChild->key)// LL型
			{
				root = avltree_ll_rotate(tree);	
			}

			if (key>root->lChild->key)//LR
			{
				root = avltree_lr_rotate(tree);
			}
			
		}
	}

	else if (key>root->key){

		root->rChild = avltree_insert(root->rChild,key);
		if (key<root->rChild->key)// RL
		{
			root = avltree_rl_rotate(tree);
		}

		if (key>root->rChild->key)// RR
		{
			root = avltree_rr_rotate(tree);

		}

	}

	return root;
}

// 删除一个节点
AVLTree* avltree_delete(AVLTree* root, KEY_TYPE key){


}


// 判断是否为AVL树
int avltree_isbalance(AVLTree *root){


}


// 查找
AVLTree* avltree_search(AVLTree *root,KEY_TYPE key){

	if (root==NULL)		
	{
		return NULL;
	}

	if (root->key == key)
	{
		return root;
	}

	else if (root->key>key)
	{
		return avltree_search(root->lChild,key);
	}

	else{

		return avltree_search(root->rChild,key);
	}


}

// 中序遍历
void avltree_inorder_traversal(AVLTree* root){

	if (root)
	{
		avltree_inorder_traversal(root->lChild);
		printf(节点值=%d,左右子树的高度差=%d\n,root->key,root->height);
		avltree_inorder_traversal(root->rChild);
	}
	

}



// test 

int main(){

	AVLTree *avlTree=NULL;
	printf("插入节点，创建一个AVL树...\n");

	int values[] = {11,7,222,456,23,8,65,124,88,2,54};
	for (int i = 0; i < sizeof(values)/sizeof(int); ++i)
	{
			printf("插入节点 %d\n", values[i]);
			avlTree = avltree_insert(avlTree,values[i]);
			avltree_inorder_traversal(avltree);
			printf("\n\n");
	}

	printf("中序遍历结果:\n");
	avltree_inorder_traversal(avlTree);
	

	printf("删除一个存在的节点 %d\n", values[1]);
	avlTree=avltree_delete(avlTree,values[1]);
	printf("中序遍历结果:\n");
	avltree_inorder_traversal(avlTree);


	printf("删除一个不存在的节点 %d\n",111 );
	avltree_delete(avlTree,111);
	printf("中序遍历结果:\n");
	avltree_inorder_traversal(avlTree);

	printf("查找一个存在的节点 %d\n", values[3]);
	avltree_search(avltree,values[3]);

	printf("查找一个不存在的节点 %d\n",51);
	avltree_search(avltree,51);


	return 0;
}









