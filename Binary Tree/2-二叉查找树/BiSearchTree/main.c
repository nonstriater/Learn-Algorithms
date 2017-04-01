//
//  main.c
//  BiSearchTree
//
//  Created by nonstriater on 14-2-22.
//
//

#include <stdio.h>
#include "bisearchtree.h"

int main(){
    
    printf("begining...\n");
    BiSearchTree *searchTree;
    searchTree = bisearch_tree_new();
    searchTree = bisearch_tree_insert(searchTree,19);// 第一次insert
    bisearch_tree_insert(searchTree,3);
    bisearch_tree_inorder_traversal(searchTree);
    
    bisearch_tree_insert(searchTree,122);
    bisearch_tree_insert(searchTree,55);
    bisearch_tree_insert(searchTree,65);
    bisearch_tree_insert(searchTree,180);
    
    printf("inorder traversal\n");
    bisearch_tree_inorder_traversal(searchTree);
    
    
    //=======search ============================================
    printf("find node...\n");
    int find = 55;
    if(bisearch_tree_search(searchTree,find)<0){
        printf("node %d not exits\n",find);
    }else{
        printf("node %d exits\n",find);
    }
    
    find = 33;
    if(bisearch_tree_search(searchTree,find)<0){
        printf("node %d not exits\n",find);
    }else{
        printf("node %d exits\n",find);
    }

    
    //====== delete,会影响到serachTree值，所以应该传递serachTree的指针 ======================================
    printf("delete node..\n");
    find = 4;
    if(bisearch_tree_delete(&searchTree,find)<0){
        printf("delete node %d failure\n",find);
    }else{
        printf("delete node %d success\n",find);
        bisearch_tree_inorder_traversal(searchTree);
        bisearch_tree_insert(searchTree,find);
    }
    
    
    find = 65;//叶子
    if(bisearch_tree_delete(&searchTree,find)<0){
        printf("delete node failure\n");
    }else{
        printf("delete node %d success\n",find);
        bisearch_tree_inorder_traversal(searchTree);
        bisearch_tree_insert(searchTree,find);
    }
    
    
    
    find = 55;//单分支
    if(bisearch_tree_delete(&searchTree,find)<0){
        printf("delete node failure\n");
    }else{
        printf("delete node %d success\n ",find);
        bisearch_tree_inorder_traversal(searchTree);
        bisearch_tree_insert(searchTree,find);
    }
    
    find = 122;//双分支
    if(bisearch_tree_delete(&searchTree,find)<0){
        printf("delete node failure\n");
    }else{
        printf("delete node %d success\n",find);
        bisearch_tree_inorder_traversal(searchTree);
        bisearch_tree_insert(searchTree,find);
    }
    
    return 0;
}

/*
 
 测试结果：
 
 begining...
 insert first node 19
 insert node 3 to left of 19
 3
 19
 insert node 122 to right of 19
 insert node 55 to left of 122
 insert node 65 to right of 55
 insert node 180 to right of 122
 inorder traversal
 3
 19
 55
 65
 122
 180
 find node...
 node 55 exits
 node 33 not exits
 delete node..
 树为空，或想要删除的节点不存在
 delete node 4 failure
 delete node 65 success
 3
 19
 55
 122
 180
 insert node 65 to right of 55
 delete node 55 success
 3
 19
 65
 122
 180
 insert node 55 to left of 65
 delete node 122 success
 3
 19
 55
 65
 180
 insert node 122 to left of 180
 
 
 
 */








