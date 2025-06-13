# 面试题

这部分内容是算法问题合集，题目大多来自网络和书籍。我做了下简单的整理，很多题做了一些思路标记。

## 小结

面试中如何更好的写算法题

* ide 工具 & 文本框 ；文本框环境写算法是通常没有智能提示，有些基础数据结构可能要自己定义
* 语言基础语法：各常用集合的api，要能够默写
* 题目：熟悉各种题目，避免在题目理解上花太多时间跟面试官拉齐
* 编程思路和框架：拿到题目以后能快速套思路和代码框架
* 编程细节：多练习，总结


## 常用解题套路工具

* 数组，字符串问题：二分查找、 快慢指针、 左右指针、 滑动窗口、 前缀和数组、 差分数组。
* 二叉树问题：递归
* [动态规划问题](../8%20Algorithms%20Analysis/动态规划.md)
* [常见算法题目Java实现](https://github.com/nonstriater/deep-in-java/tree/master/src/main/java/com/nonstriater/deepinjava/algo)


## 刷题框架套路


### 遍历

```
# 数组遍历框架
void traverse(int[] arr) {
    for (int i = 0; i < arr.length; i++) {
        // 迭代访问 arr[i]
    }
}

# 链表遍历框架
void traverse(ListNode head) {

    ListNode p = head;
    while(p.next != null)
        ...
        p = p.next
 
}
```



### 递归

```Java
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

比如，二叉树的最近公共祖先

```Java
TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        // base case
        if (root == null) return null;
        if (root == p || root == q) return root;

        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);
        // 情况 1  ：p, q 在 root 为根的树中
        if (left != null && right != null) {
            return root;
        }
        // 情况 2 ：p, q 不在 在 root 为根的树中
        if (left == null && right == null) {
            return null;
        }
        // 情况 3 ： p, q 只有1个在root 为根的树中
        return left == null ? right : left;
    }
```


### 二分查找  

[查找算法](../7%20Search/README.md)

```Java
// 1, 2, 2, 2, 2, 3
public int bsearch(int[] nums, int target){
        
        if(nums == null) {
            return -1;
        }
        
        int low = 0;
        int high =  nums.length;// 注意

        while(low < high){
            middle = (high + low ) / 2;        
            if(nums[middle] < target){
                low = middle + 1;
            } else if (nums[middle] == target) {
                high = middle;//继续向左早
            } else {
                high = middle;  // 注意 , 这里没有 -1
            }
        }
        
        return low;        
    } 
```


### 快慢指针

如下判断链表是否有环

```
public static boolean hasCycle(LinkNode head) {
        if(head == null) {
            return false;
        }

        LinkNode p = head, q = head;
        while(p.next != null && p.next.next != null && q.next != null) {
            p = p.next.next;
            q = q.next;
            if(p == q) {
                return true;
            }
        }
        return false;
    }
```


### 左右指针


快排中 挖坑(pivot) 排序
```Java
// pivot 选择 尾部节点， 代码写起来更加简单； 移动元素更方便
// 左右指针技巧
static int partition(int[] nums, int left, int right){

        int pivot = nums[right];//选尾部节点作为 pivot
        int end = right;

        right--;
        while (left < right) {

            if (nums[left] <= pivot) {
                left ++ ; //左边指针 窗口变小
                continue;
            }

            //元素比 pivot 大，右边指针 窗口变小
            //swap left & right
            swap(nums, left, right);
            right--;

        }

        // 跟 pivot 元素置换
        int i = 0;
        if (nums[left] <= pivot) {
            //swap left+1 & pivot
           i = left +1;
        } else {//swap left & pivot
           i =  left ;
        }

        swap(nums, i, end);

        return i;
    }
```


### 滑动窗口

双指针中有一类比较难的技巧就是`滑动窗口`

滑动窗口： 无重复字符的最长子串

```Java
//如 ”abcabbcbb“ 输出 3
public static int longestSubString(char[] s){
        int left = 0, right = 0;
        int res = 0; // 记录最长结果

        Map<Character, Integer> window = new HashMap<Character, Integer>();
        
        while (right < s.length) {
            Character c = s[right];
            
            //窗口变大
            right++;
            window.put(c, window.getOrDefault(c, 0) + 1); //java写的麻烦,不一定记得这个api

            if (window.get(c) > 1) {
                //判断左侧窗口是否要收缩
                char d = s[left];
                
                left ++;
                window.put(d, window.get(d)-1);
            }

            // 在这里更新答案
            res = res > (right-left) ? res: (right-left);

        }
        return res;
}        
```


### 排序算法

[排序算法](../6%20Sort/README.md)

```Java

#快排 quickSort
void quicksort(int[] nums, int left, int right){
    if (left<right){//加上这个，不然有死循环，造成堆栈溢出，这也是递归结束条件
        
        //前序遍历位置
        //使得局部有序，i作为分隔， i 前面的元素 小于 i 后面的元素
        int i = partion(a,left,right);
        
        quicksort(a,left,i-1); 
        quicksort(a,i+1,right);     
    }    
}

#归并排序 mergeSort
void mergeSort(int[] nums, int left, int right){
    int mid = (low + high) / 2;
    sort(nums, low, mid);
    sort(nums, mid + 1, high);

    /****** 后序遍历位置 ******/
    // 合并两个排好序的子数组
    merge(nums, low, mid, high);
    /************************/
}


```

### 动态规划 DP





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




# 参考
 
[九度OJ](http://ac.jobdu.com/index.php)    
[leetcode 题目](https://leetcode.com/)    
[labuladong 的算法小抄](https://labuladong.gitee.io/algo/1/2/)     
[《剑指offer》](剑指offer/README.md)  《剑指offer》里面给出了50到高质量的算法问题，很有学习的必要。    
[《编程之美》](编程之美/README.md)    
 


