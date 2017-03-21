
### 分布处理之Mapreduce

MapReduce是Google提出的一个软件架构，用于大规模数据集（大于1TB）的并行运算。概念“Map（映射）”和“Reduce（归纳）”，及他们的主要思想，都是从函数式编程语言借来的，还有从矢量编程语言借来的特性。MapReduce的伟大之处就在于让不熟悉并行编程的程序员也能充分发挥分布式系统的威力。


##### Mapreduce工作原理

举一个例子：10年内所有论文(当然有很多很多篇)里面出现最多的几个单词。

我们把论文集分层N份，一台机器跑一个作业。这个方法跑得快，但是有部署成本，需要把程序copy到别的机器，要把论文分N份，且还需要最后把N个运行结果整合起来。这其实就是Mapreduce本质。


map函数和reduce函数是交给用户实现的，这两个函数定义了任务本身。

* map函数：接受一个键值对（key-value pair），产生一组中间键值对。MapReduce框架会将map函数产生的中间键值对里键相同的值传递给一个reduce函数。Map操作是可以高度并行的。
* reduce函数：接受一个键，以及相关的一组值，将这组值进行合并产生一组规模更小的值（通常只有一个或零个值）。



##### Hadoop

谷歌技术有"三宝"，GFS、MapReduce和大表（BigTable）。

Hadoop实际上就是谷歌三宝的开源实现，Hadoop MapReduce对应Google MapReduce，HBase对应BigTable，HDFS对应GFS。HDFS（或GFS）为上层提供高效的非结构化存储服务，HBase（或BigTable）是提供结构化数据服务的分布式数据库，Hadoop MapReduce（或Google MapReduce）是一种并行计算的编程模型，用于作业调度。

Hadoop 使用java实现。

