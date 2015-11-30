
>算法虐我千百遍，我待算法如初恋

这里的内容是我学习算法过程的一些记录，希望能一直坚持下去。

##学习方法
 
* 把所有经典算法写一遍  
* 看算法源码   
* 加入算法学习社区，相互鼓励学习   
* 看经典书籍  
* 刷题   


##基本数据结构和算法

这些算法全部自己敲一遍：

###二叉树

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

  
###哈希表/散列表 (Hash Table)
  
  
###字符串算法  

* 排序
* 查找
    * BF算法  
    * KMP算法  
    * BM算法  
    
###图的算法

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
* 
* 快排   
* 归并排序  
* 堆排序

**线性排序算法**
  
* 基数排序  
  
  
### 查找算法  

* 顺序表查找：顺序查找  
* 有序表查找：二分查找  
* 分块查找： 块内无序，块之间有序；可以先二分查找定位到块，然后再到`块`中顺序查找  
* 动态查找:  二叉排序树，AVL树，B- ，B+    （这里之所以叫 `动态查找表`，是因为表结构是查找的过程中动态生成的）
* 哈希表：  O(1)     


###15个经典基础算法

* A*寻路算法： 求解最短路径 
* Dijkstra：最短路径算法 （八卦下：Dijkstra是荷兰的计算机科学家,提出”信号量和PV原语“,"解决哲学家就餐问题",”死锁“也是它提出来的） 
* DP (动态规划 dynamic programming)   
* BFS/DFS （广度/深度优先遍历）    
* 红黑树 （一种自平衡的`二叉查找树`）  
* KMP    字符串匹配算法   
* 遗传算法  
* 启发式搜索   
* 图像特征提取之SIFT算法  
* 傅立叶变换  
* Hash  
* 快速排序  
* SPFA(shortest path faster algorithm)  单元最短路径算法  
* 快递选择SELECT    
  
    
  
## 算法设计思想

为了更简洁的形式设计和藐视算法，在算法设计时又常常采用递归技术，用递归描述算法。  
  
  
* 迭代法  
* 穷举搜索法  
* 递推法  
* 
* 动态规划  
* 贪心算法  
* 回溯  
* 分治算法  

http://www.chinaunix.net/old_jh/23/437639.html



## 推荐阅读


### 刷题必备  

《剑指offer》  
《编程之美》  
《结构之法:面试和算法心得》  

### 基础

《编程珠玑》Programming Pearls   
《编程珠玑(续)》   
《数据结构与算法分析》   
《Algorithms》 这本近千页的书只有6章,其中四章分别是排序，查找，图，字符串，足见简介细致     

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


###基本算法演示 

http://sjjg.js.zwu.edu.cn/SFXX/sf1/sfys.html  
http://www.cs.usfca.edu/~galles/visualization/Algorithms.html  
  
   
###编程网站

http://leetcode.com/  
http://oj.leetcode.com/  
http://openjudge.cn/   POJ。这有个POJ上的ACM训练方案 http://www.java3z.com/cwbwebhome/article/article19/res041.html  
http://ac.jobdu.com/index.php  九度OJ  
  

## 补充:C语言代码规范

这里面的算法代码均使用C语言完成，养成良好的代码规范习惯，不但可以写出优质的代码，也可以更快的阅读其他优秀开源代码。代码规范主要有：

### 符号命名

**局部变量** 尽量短，能表达清楚意思即可，能简写就简写，比如"err" 表示 "error"; "fd" 表示文件描述符 ，循环变量可以使用i,j,k ;结构体成员变量不需要"m_"前缀;全局变量"g_"开头

**常量名** 全大写，单词之间"_"分割，如 "MAX_NUMBER_OF_SLAB_CLASSES" ;

**宏定义** 对于options 宏定义，适当使用前缀 ，比如：
```
/* Client classes for client limits, currently used only for
 * the max-client-output-buffer limit implementation. */
#define CLIENT_TYPE_NORMAL 0 /* Normal req-reply clients + MONITORs */
#define CLIENT_TYPE_SLAVE 1  /* Slaves. */
#define CLIENT_TYPE_PUBSUB 2 /* Clients subscribed to PubSub channels. */
#define CLIENT_TYPE_MASTER 3 /* Master. */
#define CLIENT_TYPE_OBUF_COUNT 3 
```

**枚举** 使用前缀:
```
enum conn_states {
    conn_listening,  /**< the socket which listens for connections */
    conn_new_cmd,    /**< Prepare connection for next command */
    conn_waiting,    /**< waiting for a readable socket */
    conn_read,       /**< reading in a command line */
    conn_parse_cmd,  /**< try to parse a command from the input buffer */
    conn_write,      /**< writing out a simple response */
    conn_nread,      /**< reading in a fixed number of bytes */
    conn_swallow,    /**< swallowing unnecessary bytes w/o storing */
    conn_closing,    /**< closing this connection */
    conn_mwrite,     /**< writing out many items sequentially */
    conn_closed,     /**< connection is closed */
    conn_max_state   /**< Max state value (used for assertion) */
};
```

**函数命名** 全小写，单词之间"_"分割。如"split_cmdline_strerror()"  


### 注释

所有注释使用 "/* 这里是注释 */ "


### 其他

合理使用static,const 等关键字,能提升程序的安全性，也能避免函数命名冲突  
合理使用数据类型：rel_time_t,uint8_t,uint32_t,uint64_t,size_t,off_t


## 联系

[@移动开发小冉](http://weibo.com/ranwj)



