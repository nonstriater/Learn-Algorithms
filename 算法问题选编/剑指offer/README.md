
《剑指offer》 这本书给出了50到面试题，涉及到字符串处理，堆栈，链表，二叉树等问题的处理。

* 代码鲁榜性：边界条件，特殊输入，异常处理：空指针  
* 分析方法：画图，举例，分解  
* 查找和排序是常考：重点掌握二分查找，快速排序，归并排序  
* 本书完整源代码在：


### 赋值运算符函数  
### 实现Singleton模式


### 二维数组中的查找

二维数组中每一行从左到右递增，每一列从上到下递增，判断数组中是否包含该整数。

```
bool find(int *matrix,int rows,int columns,int numbers)
```


### 替换空格

如把字符串中的每个空格替换成`%20` 

`二遍扫描` 

```
void replace_blank(char *str);
```


### 从尾到头打印链表 

`栈`

```
void print_reversing(LinkList *head)
```


### 重建二叉树

输入某二叉树的前序遍历和中序遍历的结果，重建该二叉树

```
BinaryTree *construct(int *preorder,int inroder,int length);
```


### 用两个栈实现队列

队列就是在尾部插入节点，头部删除节点。


### 旋转数组的最小数字

旋转数组是指把一个数组最开始的若干个元素搬到数组的末尾。输入一个递增排序的数组的旋转，比如{3，4，5，1，2}是{1，2，3，4，5}的一个旋转。求该数组的最小值。

```
int min(int *num, int length)
```

### 菲波那切数列

```
long long fabonacci(unsigned n)
```

### 二进制中1的个数  

输入一个整数，输出该数二进制中1出现的次数。比如9的二进制 10001，输出是2

`n=n&n-1`

```
int one_appear_count(int n)
```

### 数值的整数次方

要求不得使用库函数。这里注意考虑指数是0和负数的情况

```
double power(double base,int exponent)
```


### 打印1到最大的n位数

比如n=3，就打印1到999

```
void print_to_max_with_length(int n)
```


### 在O(1)时间删除链表节点

已经有一个头节点指针，还有一个指向改删除节点的指针  

`用下一个节点的内容覆盖当前删除节点的内容，删除下一个节点`

```
void deleteNode(LinkList *head,LinkList *targetToDelete);
```


### 调整数组顺序使奇数位于偶数前面

调整后，所有奇数在前半部分，偶数在后半部分

`两边向中间扫描`


```
void reorder(int *data,int length)
```


### 输出链表中倒数第K个节点

`使用两个指针，一个先走k-1步`

```
void print_lastK(LinkList *head);
```


### 反转链表

`三个指针`

```
void reverse(LinkList *head);
```


反转二叉树呢？


### 合并2个排序的链表

要求合并以后链表任然排序

`递归`

```
LinkList *merge(LinkList *one,LinkList *two);
```


### 树的子结构

考察二叉树的基本操作。输入2课二叉树A和B，判断B是不是A的子结构。

```
struct BinaryTreeNode{
	int m_value;
	BinaryTreeNode *m_pleft;
	BinaryTreeNode *m_pRight;
}
```


```
		8   				
	   / \				   10
	  /   \				   / \						
	 6     10	 子结构	  11  9   
	/ \	   / \            
   5   7  9  11   	    
```

```
bool subTree(BinaryTreeNode *root1,BinaryTreeNode *root2);
```



### 二叉树翻转

```
		8   				8
	   / \				   / \
	  /   \				  /   \   						
	 6     10	 翻转后	10	   6
	/ \	   / \          / \   / \
   5   7  9  11   	   11  9 7   5
``` 
   
`交换每个节点的左右子树`	   

```
void reverse(BinaryTreeNode *root);
```


### 从外向里顺时针打印矩阵

```
void print_matrix_clockwise(int *matrix,int cols,int rows);
```

延伸：按大小顺序打印矩阵

### 实现一个能找到栈的最小元素的函数

`最小元素用辅助栈保存`

```
int min(Stack *stack)
```


### 栈的压入，弹出序列

输入2个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。比如：

1，2，3，4，5是压栈序列，4，5，3，2，1是弹栈序列，但是4，3，5，1，2就不是弹栈序列

```
bool is_pop_order(int *push,int *pop,int length)
```


### 从上往下打印二叉树

`辅助队列`

```
void print_binary_level(BinaryTreeNode *root)
```


### 二叉搜索树的后续遍历序列

输入一个整数数组，判断该数组是不是某二叉查找树的后续遍历序列的结果。比如【 5，7，6，9，11，10，8】 是下面二叉查找树的后续遍历结果：

```
		8   			
	   / \				   
	  /   \				    						
	 6     10	 
	/ \	   / \         
   5   7  9  11   	   
```

`寻找规律`

```
bool is_post_order(BST *root,int *data, int length);
```


### 二叉树中和为某一值的路径

```
	   10   			
	   / \				   
	  /   \				    						
	 5     12	 
	/ \	           
   5   7    
```

和为22的路径有2条：10--5--7， 10--12

`递归，栈`

```
void print_path(BinaryTree *root,int n)
```


### 复杂链表的复制

在复杂链表结构中，每个节点都有一个指向下一个节点的m_pNext;还有一个指向任意节点的m_pSibling

```
typedef struct LinkListNode{
	int m_value;
	LinkListNode *m_pNext;
	LinkListNode *m_pSlbling;
}LinkList;
```

```
LinkList * copy(LinkList *head);
```

### 二叉搜索树与双向链表

将二叉搜索树转换成一个排序的双向链表，只调整树中节点的指针指向

`递归` `分解问题`

```
BST *transform(BST *root);
```


### 字符串的排列

输入一个字符串，打印该字符串中字符的所有排列

`递归，分解`

```
void print_full_permutation(char *string)
```


### 数组中出现次数超过一半的数字

`遍历数组，下一个数字和之前保存的数字一样就+1，否则就-1`

```
int find_more_than_half_num(int *nums ,int length)
```


### n个整数中最小的K个数

`快速排序` `最大堆`

```
void find_least_k(int *data,int n,int *ouput,int k)
```


最大的K个数呢？


### 连续子数组的最大和

输入一个整数数组，有正有负，求所有子数组的和的最大值

`分析规律` `动态规划`


```
int max_of_subarray(int *data,int length)
```


### 从1到n整数中，1出现的次数

比如 12，从1到12这些整数中，包含1的数字有 1， 10，11，12 ，1出现了5次

```
int one_appear_count(int n)
```


### 把数组排成最小的数

输入一个正整数数组,把所有数字拼起来排出一个最小数

```
int minSort(int *nums, int length);
```

###  丑数

> 只包含因子 2，3，5的数叫做丑数

求按从小到大的顺序，第1500个丑数

```
int ugly(int n)
```


###  第一个只出现一次的字符

在字符串中查找第一个只出现一次的字符

`哈希表：值为出现的次数` `二次扫描`

```
char find_appear_once_char(char *string)
```


###  数组中的逆序对

>数组中的两个数字如果前面一个数字大于后面的数字，这两个数字组成一个逆序对。如：[7，5，6，4] 的逆序对：(7,5)(7,6)(7,4)(5,4)(6,4)

输入一个数组，求出这个数组逆序对总数。

`归并排序 O(nlogn),空间O(n)`


```
int reversePairs(int *data,int length)
```


###  两个链表的第一个公共节点

`长的链表先走k步`


```
LinkListNode *common_node(LinkList *head1,LinkList head2);
```


### 数字在排序数组中出现的次数

比如 {1，2，3，3，3，3，4，5}， 数字 3出现了4次

`使用二分查找找第一个3，和最后一个3出现的位置`

```
int appear_count(int *nums,int length,int n);
```


###  二叉树的深度

`递归`


```
int tree_depth(BTree *root);
```

### 数组中只出现一次的数字

数组中除了2个数字之外，其他的数组都出现了2次，找出这两个数

`异或` `二进制`

>如果是只有1个数字只出现一次，我们可以通过对数组依次做异或运算。

如果我们能把原数组分成2个子数组，每个子数组都包含一个只出现一次的数字，问题就能解决了。我们把数组中的所有数字依次做异或操作，如果有2个数字不一样，结果肯定不是0，且异或结果数字的二进制表示中至少有一位是1（不然结果不就是0了）

1. 在结果数字二进制表示中找到第一个为1的位的位置，标记n
2. 以二进制表示中第n位是不是1为标准，把原数组分成2个子数组


```
void find_two_numbers_appear_once(int *data,int length,int *ouput)
```


### 和为s的两个数字 VS  和为s的连续正数序列

有一个递增排序数组，和一个数字s，找出数组中的2个数，使得和等于s。输出任意一对即可

`两边向中间扫描`


```
void print_two_numbers(int *data,int length,int sum)
```

### 反转单词顺序 VS 左旋转字符串

a. 翻转句子中单词的顺序，但单词内字符不变。如 『I am a student』 ->  『student. a am I』

`先以单词为单位翻转,整个句子再次翻转`


```
char *reverse_by_word(char *string)
```

b. 左旋转字符串是把字符串其那面的若干位转义到字符串的尾部。比如"abcedfsz"和数字2，结果是"cedfszab"

```
char *left_rotate_string(char *s,int n)
```


### n个色子的点数

把n个色子丢地上，朝上一面的点数之和为s。输入n，打印可能的值出现的概率


```
void print_sum_probability(int n)
```


### 扑克牌中的顺子

从扑克牌从随机抽5张牌，判断是不是顺子。A是1，J~K是11~13，大小王可以看出任意数字。


```
bool is_straight(int *data,int length)
```

### 圆圈中最后剩下的数字(约瑟夫问题)

0,1,...,n-1 这n个数字排成一个圆圈，从数字0开始从这个圆圈里面删除第m个数字，求出这个圆圈里最后剩下的数字。


```
int last_remaining(unsigned int n,unsigned int m)
```

### 求 1+2+...+n

要求不用乘除法，for/while/if/else/switch等关键字及条件判断语句


```
long long sum(unsigned int n);
```

### 不用加减乘除做加法

求2个整数之和

`位运算`


```
int sum(int,int)
```


### 不能被继承的类

```

```


### 把字符串转换成整数

比如 "12343567754" -> 12343567754


`NULL,空串,正负号,溢出`


```
int strToInt(char str);
```

### 树中2个结点的最低公共祖先

如果这个树是二叉排序树  
如果不是二叉排序树，但是有父节点指针  
如果不是二叉树，也没有父节点指针  
















