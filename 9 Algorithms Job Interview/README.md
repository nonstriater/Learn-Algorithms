# 面试题

这部分内容是算法问题合集，题目大多来自网络和书籍。我做了下简单的整理，很多题做了一些思路标记。

## 小结

面试中如何更好的写算法题

* ide 工具 & 文本框 ；文本框环境写算法是通常没有智能提示，有些基础数据结构可能要自己定义
* 语言基础语法：各常用集合的api，要能够默写
* 题目：熟悉各种题目，避免在题目理解上花太多时间跟面试官拉齐
* 编程思路和框架：拿到题目以后能快速套思路和代码框架
* 编程细节：多练习，总结


常用解题套路工具

* 数组，字符串问题：二分查找、 快慢指针、 左右指针、 滑动窗口、 前缀和数组、 差分数组。
* 二叉树问题：递归
* [动态规划问题](../8%20Algorithms%20Analysis/动态规划.md)


## [字符串](1%20字符串.md)

计算机处理的数据除了数值，就是字符。字符处理的常见问题包括：

* 单词反转  
* 回文判断  
* 字符串的压缩  
* 字符串的排列和组合  
* 字符串比较  
* 子串  


## [链表](2%20链表.md)

链表处理的常见问题包括：

* 链表反转
* 链表中是否有环
* 删除链表中的p节点,在p节点前面插入节点q， 要求O(1)复杂度
* 2个链表相交
* 2个链表合并


## [栈和队列](3%20堆和栈.md)

这是最基本数据结构，相对容易理解。



## [数值问题](4%20数值问题.md)

这部分都是一些数学几何计算方面的问题。  主要有：

* 位运算
* 随机数
* 大数问题


## [数组数列问题](5%20数组数列问题.md)


这部分的问题都集中在数据集合上。主要有：

* 数组排序
* top-k
* 子数组
* 多个数组合并，交集


## [矩阵](6%20矩阵.md)

这部分都是矩阵和二维数组相关的问题。


## [二叉树](7%20二叉树.md)

常见问题

* 遍历
* 翻转
* 子树

解题思路：递归

## [图](8%20图.md)

图相关的问题



## [智力思维训练](9%20智力思维训练.md)



# 刷题框架套路

遍历

```
# 数组遍历框架
void traverse(int[] arr) {
    for (int i = 0; i < arr.length; i++) {
        // 迭代访问 arr[i]
    }
}

# 链表遍历框架
void traverse(ListNode head) {
    for (ListNode p = head; p != null; p = p.next) {
        // 迭代访问 p.val
    }
}

```


递归

```
# 链表递归
void traverse(ListNode head) {
    // 递归访问 head.val
    traverse(head.next);
}


# 二叉树递归
void traverse(TreeNode root) {
    traverse(root.left);
    traverse(root.right);
}

# 多叉树递归
void traverse(TreeNode root) {
    for (TreeNode child : root.children)
        traverse(child);
}

# 图的递归：，用个布尔数组 visited 做标记就行了


```



# 参考
 
[九度OJ](http://ac.jobdu.com/index.php)    
[leetcode 题目](https://leetcode.com/)    
[labuladong 的算法小抄](https://labuladong.gitee.io/algo/1/2/)     
[《剑指offer》](剑指offer/README.md)  《剑指offer》里面给出了50到高质量的算法问题，很有学习的必要。    
[《编程之美》](编程之美/README.md)    
 


