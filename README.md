

>算法虐我千百遍，我待算法如初恋

这里的内容是我学习算法过程的一些记录，希望能一直坚持下去。

## 学习方法
 
* 把所有经典算法写一遍  
* 看算法有关源码   
* 加入算法学习社区，相互鼓励学习   
* 看经典书籍  
* 刷题   


## 基本数据结构和算法

这些算法全部自己敲一遍：

### 链表

* 链表
* 双向链表
 
### 哈希表/散列表 (Hash Table)

* 散列函数
* 碰撞解决

### 字符串算法  

* 排序
* 查找
    * BF算法  
    * KMP算法  
    * BM算法  
* 正则表达式
* 数据压缩


### 二叉树

* 二叉树    
* 二叉查找树   
* 伸展树(splay tree 分裂树)   
* 平衡二叉树AVL    
* 红黑树  
* B树,B+,B*  
* R树  
* Trie树(前缀树)  
* 后缀树  
* 最优二叉树(赫夫曼树) 
* 二叉堆 （大根堆，小根堆）   
* 二项树    
* 二项堆  
* 斐波那契堆(Fibonacci Heap)   


### 图的算法

* 图的存储结构和基本操作（建立，遍历，删除节点，添加节点）   
* 最小生成树  
* 拓扑排序  
* 关键路径  
* 最短路径: Floyd,Dijkstra,bellman-ford,spfa  
  
  
  
### 排序算法

**交换排序算法**

* 冒泡排序
* 插入排序    
* 选择排序    
* 希尔排序
* 快排   
* 归并排序  
* 堆排序

**线性排序算法**
    
* 桶排序 
  
  
### 查找算法  

* 顺序表查找：顺序查找  
* 有序表查找：二分查找  
* 分块查找： 块内无序，块之间有序；可以先二分查找定位到块，然后再到`块`中顺序查找  
* 动态查找:  二叉排序树，AVL树，B- ，B+    （这里之所以叫 `动态查找表`，是因为表结构是查找的过程中动态生成的）
* 哈希表：  O(1)     


### 15个经典基础算法

* Hash  
* 快速排序 
* 快递选择SELECT 
* BFS/DFS （广度/深度优先遍历）    
* 红黑树 （一种自平衡的`二叉查找树`）  
* KMP    字符串匹配算法
* DP (动态规划 dynamic programming)   
* A*寻路算法： 求解最短路径 
* Dijkstra：最短路径算法 （八卦下：Dijkstra是荷兰的计算机科学家,提出”信号量和PV原语“,"解决哲学家就餐问题",”死锁“也是它提出来的） 
* 遗传算法  
* 启发式搜索   
* 图像特征提取之SIFT算法  
* 傅立叶变换  
* SPFA(shortest path faster algorithm)  单元最短路径算法  
    


## 海量数据处理

* Hash映射/分而治之
* Bitmap
* Bloom filter(布隆过滤器)
* Trie树
* 数据库索引
* 倒排索引(Inverted Index)
* 双层桶划分
* 外排序
* simhash算法
* 分布处理之Mapreduce


## 算法设计思想
 
* 迭代法  
* 穷举搜索法  
* 递推法  
* 动态规划  
* 贪心算法  
* 回溯  
* 分治算法  


## 算法问题选编

这是一个算法题目合集，题目是我从网络和书籍之中整理而来，部分题目已经做了思路整理。问题分类包括：

* 字符串
* 堆和栈
* 链表
* 数值问题
* 数组和数列问题
* 矩阵问题
* 二叉树
* 图
* 海量数据处理
* 智力思维训练
* 系统设计

还有部分来自算法网站和书籍：

* 九度OJ
* leetcode
* 剑指offer


## 开源项目中的算法

* YYCache
* cocos2d-objc
* ...


## 推荐阅读

### 刷题必备  

《剑指offer》  
《编程之美》  
《编程之法:面试和算法心得》      
《算法谜题》 都是思维题 

### 基础

《编程珠玑》Programming Pearls   
《编程珠玑(续)》   
《数据结构与算法分析》   
《Algorithms》 这本近千页的书只有6章,其中四章分别是排序，查找，图，字符串，足见介绍细致     

### 算法设计 

《算法设计与分析基础》    
《算法引论》 告诉你如何创造算法   断货        
《Algorithm Design Manual》算法设计手册 红皮书  

《算法导论》 是一本对算法介绍比较全面的经典书籍   
     
《Algorithms on Strings,Trees and Sequences》    
《Advanced Data Structures》 各种诡异高级的数据结构和算法 如元胞自动机、斐波纳契堆、线段树  600块    
  
 
### 延伸阅读 
   
《深入理解计算机系统》    
《TCP/IP详解三卷》    
《UNIX网络编程二卷》  
《UNIX环境高级编程：第2版》  
    
     
《The practice of programming》   Brian Kernighan和Rob Pike    
《writing efficient programs》  优化   
《The science of programming》 证明代码段的正确性   800块一本   


## 参考链接和学习网站

### [July 博客](http://blog.csdn.net/v_july_v) 

《数学建模十大经典算法》    
《数据挖掘领域十大经典算法》    
《十道海量数据处理面试题》      
《数字图像处理领域的二十四个经典算法》    
《精选微软等公司经典的算法面试100题》 


[The-Art-Of-Programming-By-July](https://github.com/julycoding/The-Art-Of-Programming-By-July)   
[微软面试100题](http://blog.csdn.net/column/details/ms100.html)   
[程序员编程艺术](http://blog.csdn.net/v_JULY_v/article/details/6460494)   


### 基本算法演示 

http://sjjg.js.zwu.edu.cn/SFXX/sf1/sfys.html  
http://www.cs.usfca.edu/~galles/visualization/Algorithms.html  
  
   
### 编程网站

[leetcode](http://leetcode.com/)    
[openjudge](http://openjudge.cn/)  开放在线程序评测平台，可以床架自己的OJ小组  
[九度OJ](http://ac.jobdu.com/index.php)     
  
这有个[ACM训练方案](http://www.java3z.com/cwbwebhome/article/article19/res041.html)   

### 其它

[高级数据结构和算法](https://www.coursera.org/learn/gaoji-shuju-jiegou/)  北大教授张铭老师在coursera上的课程。完成这门课之时，你将掌握多维数组、广义表、Trie树、AVL树、伸展树等高级数据结构，并结合内排序、外排序、检索、索引有关的算法，高效地解决现实生活中一些比较复杂的应用问题。当然coursera上也还有很多其它算法方面的视频课程。


[算法设计与分析 Design and Analysis of Algorithms](https://class.coursera.org/algorithms-001/lecture) 由北大教授Wanling Qu在coursera讲授的一门算法课程。首先介绍一些与算法有关的基础知识，然后阐述经典的算法设计思想和分析技术，主要涉及的算法设计技术是：分治策略、动态规划、贪心法、回溯与分支限界等。每个视频都配有相应的讲义（pdf文件）以便阅读和复习。




## 联系

[@移动开发小冉](http://weibo.com/ranwj)



