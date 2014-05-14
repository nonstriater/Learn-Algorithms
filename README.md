
>算法虐我千百遍，我待算法如初恋。


##学习方法
 
1） 把所有经典算法写一遍  
2） 看算法源码   
3） 加入算法学习社区，相互鼓励学习   
4） 看经典书籍  
  


##基本数据结构和算法

这些算法全部自己敲一遍：

###二叉树
二叉树    
二叉查找树  
Trie树(前缀树)  
后缀树  
最优二叉树(赫夫曼树)  
伸展树(splay tree 分裂树)   
平衡二叉树AVL    
红黑树  
B树(B-),B+,B*  
R树  
  
  
二叉堆 （大根堆，小根堆）   
二项树    
二项堆  
斐波那契堆(Fibonacci Heap)   
  
  
###哈希表/散列表 (Hash Table)
  
  
###字符串算法  

BF算法  
KMP算法  
BM算法  
  
  
###图的算法

图的存储结构和基本操作（建立，遍历，删除节点，添加节点）   
最小生成树  
拓扑排序  
关键路径  
最短路径: Floyd,Dijkstra,bellman-ford,spfa  
  
  
  
### 排序算法

*交换排序算法*  
插入排序     
选择排序    
希尔排序

堆排序  
快排   
归并排序  


*线性排序算法*
基数排序  
  
  
### 查找算法  
顺序表查找：顺序查找  
有序表查找：二分查找  
分块查找： 块内无序，块之间有序；可以先二分查找定位到块，然后再到`块`中顺序查找    中使用顺序查找（这里之所以叫 `动态查找表`，是因为表结构是查找的过程中动态生成的）    
动态查找:  二叉排序树，AVL树，B- ，B+    
哈希表：  O(1)     



###15个经典基础算法

A*寻路算法： 求解最短路径 
Dijkstra：最短路径算法 （八卦下：Dijkstra是荷兰的计算机科学家,提出”信号量和PV原语“,"解决哲学家就餐问题",”死锁“也是它提出来的）     
DP (动态规划 dynamic programming)   
BFS/DFS （广度/深度优先遍历）    
红黑树 （一种自平衡的`二叉查找树`）  
KMP    字符串匹配算法   
遗传算法  
启发式搜索   
图像特征提取之SIFT算法  
傅立叶变换  
Hash  
快速排序  
SPFA(shortest path faster algorithm)  单元最短路径算法  
快递选择SELECT    
  
    
  
## 算法设计思想

为了更简洁的形式设计和藐视算法，在算法设计时又常常采用递归技术，用递归描述算法。  
  
  
迭代法  
穷举搜索法  
递推法  

动态规划  
贪心算法  
回溯  
分治算法  

http://www.chinaunix.net/old_jh/23/437639.html



## 推荐阅读

 *刷题必备*  
《剑指offer》    
《编程之美》  
《编程珠玑》Programming Pearls  偏算法理论   
《编程珠玑(续)》    
《More Programming Pearls》  偏算法轶事    
    
  
《数据结构与算法分析》    
《算法设计与分析基础》    
《算法导论》 告诉你有哪些算法  
《算法引论》 告诉你如何创造算法   断货  
  
  
*侧重经典算法的实现*  
《Elements of Programming》 STL代码 快 准 狠 ，写出的代码可以上层次   
《C interfaces and Implementation》  
《The practice of programming》   Brian Kernighan和Rob Pike
  
《微软的梦工厂》  
《Language Implementatin patterns》  
《Algorithms on Strings,Trees and Sequences》  
  
  
《writing efficient programs》  优化  
  
《Algorithm Design Manual》 红皮书  
  
《The science of programming》 证明代码段的正确性   800块一本  
  
  
*高级数据结构*（如元胞自动机、斐波纳契堆、线段树）  
   
《Algorithms》 4版  
《Advanced Data Structures》 各种诡异数据结构和算法  600块  

  
    
《深入理解计算机系统》    
《TCP/IP详解三卷》    
《UNIX网络编程二卷》  
《UNIX环境高级编程：第2版》  
    
 
  
## 参考链接和学习网站


** @ July 博客<http://blog.csdn.net/v_july_v> **  
《数学建模十大经典算法》    
《数据挖掘领域十大经典算法》    
《十道海量数据处理面试题》      
《数字图像处理领域的二十四个经典算法》    
《精选微软等公司经典的算法面试100题》 

微软面试100题 http://blog.csdn.net/column/details/ms100.html  
程序员编程艺术 http://blog.csdn.net/v_JULY_v/article/details/6460494  



https://github.com/julycoding/The-Art-Of-Programming-By-July  算法题集合
https://github.com/activesys/libcstl   通用数据结构和算法库  
https://github.com/nonstriater/Learn-Algorithm  算法小组

  
  
贝叶斯：  
1. 阮一峰总结的这两篇《贝叶斯推断及其互联网应用》   
http://www.ruanyifeng.com/blog/2011/08/bayesian_inference_part_one.html  
http://www.ruanyifeng.com/blog/2011/08/bayesian_inference_part_two.html  
2. 算法杂货铺——分类算法之朴素贝叶斯分类(Naive Bayesian classification)  
http://www.cnblogs.com/leoo2sk/archive/2010/09/17/naive-bayesian-classifier.html  
3. 朴素贝叶斯（NB,Naive Bayes)简介  
http://home.cnblogs.com/group/topic/40112.html  
4. 数学之美番外篇：平凡而又神奇的贝叶斯方法  
http://mindhacks.cn/2008/09/21/the-magical-bayesian-method/  
  
这4部分看完后，就能自己推贝叶斯、朴素贝叶斯，还能了解各种常见概率、集合论等，实际上对应用贝叶斯已经可以打好基础了。  
  
  
MYSQL 背后的数据结构和算法 http://blogread.cn/it/article/4088?f=wb2  
  
  
**基本算法演示**  
http://sjjg.js.zwu.edu.cn/SFXX/sf1/sfys.html  
http://www.cs.usfca.edu/~galles/visualization/Algorithms.html  
  
  
   
**编程网站**

http://leetcode.com/  
http://oj.leetcode.com/  
http://openjudge.cn/   POJ。这有个POJ上的ACM训练方案 http://www.java3z.com/cwbwebhome/article/article19/res041.html  
http://ac.jobdu.com/index.php  九度OJ  
  



