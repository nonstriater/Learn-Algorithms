//
//  bisearchtree.h
//  BiSearchTree
//
//  Created by nonstriater on 14-2-22.
//
//

/**
 *  
 二叉查找树（Binary search tree），也叫有序二叉树（Ordered binary tree）,排序二叉树(Sorted binary tree)。是指一个空树或者具有下列性质的二叉树：
 
 1.	若任意节点的左子树不为空，则左子树上所有的节点值小于它的根节点值
 2.	若任意节点的右子树不为空，则右子树上所有节点的值均大于它的根节点的值
 3.	任意节点左右子树也为二叉查找树
 4.	没有键值相等的节点
 
 */

#ifndef BiSearchTree_bisearchtree_h
#define BiSearchTree_bisearchtree_h

typedef int ElemType;
typedef struct BiSearchTree{
    
    ElemType key;
    struct BiSearchTree *lChild;
    struct BiSearchTree *rChild;
    
    
}BiSearchTree;


/**
 *  创建二叉查找树
 *
 *  @return 指向一颗空树的指针
 */
BiSearchTree *bisearch_tree_new();

/**
 *  插入节点
 *
 *  @param tree tree
 *  @param node 节点值
 */
BiSearchTree *bisearch_tree_insert(BiSearchTree *tree,ElemType node);

/**
 *  查找节点
 *
 *  @param tree tree
 *  @param node 节点值
 *  @return -1失败 0 成功 
 */
int bisearch_tree_search(BiSearchTree *tree,ElemType node);

//删除节点
int bisearch_tree_delete(BiSearchTree **tree,ElemType node);

// 遍历节点
void bisearch_tree_inorder_traversal(BiSearchTree *tree);


#endif
