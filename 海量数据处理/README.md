
## 海量数据处理

所谓海量数据，就是数据量太大，要么在短时间内无法计算出结果，要么数据太大，无法一次性装入内存。

针对时间，我们可以使用巧妙的算法搭配合适的数据结构，如bitmap/堆/trie树等  
针对空间，就一个办法，大而化小，分而治之。常采用hash映射


### 估算

在处理海量问题之前，我们往往要先估算下数据量，能否一次性载入内存？如果不能，应该用什么方式拆分成小块以后映射进内存？每次拆分的大小多少合适？以及在不同方案下，大概需要的内存空间和计算时间。

比如,我们来了解下以下常见问题`时间` 和 `空间` 估算 :

```
8位的电话号码，最多有99 999 999个
IP地址
1G内存，2^32 ,差不多40亿，40亿Byte*8 = 320亿 bit

```


海量处理问题常用的分析解决问题的思路是：

* 分而治之/Hash映射 + hash统计/trie树/红黑树/二叉搜索树 + 堆排序/快速排序/归并排序
* 双层桶划分
* Bloom filter 、Bitmap
* Trie树/数据库/倒排索引
* 外排序
* 分布处理之 Hadoop/Mapreduce



### 分而治之/Hash映射

这里的`Hash映射`是指通过一种映射散列的方式，将海量数据均匀分布在对应的内存或更小的文件中

使用hash映射有个最重要的特点是: `hash值相同的两个串不一定一样，但是两个一样的字符串hash值一定相等`。哈希函数如下：

```
int hash = 0;
for (int i=0;i<s.length();i++){
	hash = (R*hash +s.charAt(i)%M);
}
```

大文件映射成多个小文件。具体操作是，比如要拆分到100(M)个文件：

1. 对大文件中的每条记录求hash值，然后对M取余数，即 `hash(R)%M`，结果为K
2. 将记录R按结果K分配到第K个文件，从而完成数据拆分

这样，两条相同的记录肯定会被分配到同一个文件。



### Bitmap

也就是用1个(或几个)bit位来标记某个元素对应的value(如果是1bitmap，就只能是元素是否存在;如果是x-bitmap,还可以是元素出现的次数等信息)。使用bit位来存储信息，在需要的存储空间方面可以大大节省。应用场景有：


1. 排序（如果是1-bitmap,就只能对无重复的数排序）
2. 判断某个元素是否存在

比如，某文件中有若干8位数字的电话号码，要求统计一共有多少个不同的电话号码？

分析：8位最多99 999 999, 如果1Byte表示1个号码，需要95MB空间，但是如果1bit表示1个号码，则只需要 95/8=12MB 的空间。这时，数字k(0~99 999 999)与bit位的对应关系是：

```
#define SIZE 15*1024*1024
char a[SIZE];
memset(a,0,SIZE);

// a[k/8]这个字节中的 `k%8` 位命中,置为1
// 这里要注意 big-endian 和  little-endian的问题 ，假设这里是big-endian
a[k/8] = a[k/8] | (0x01 << (k%8))

```


### Bloom filter(布隆过滤器)

Bloom Filter是由Bloom在1970年提出的一种多哈希函数映射的快速查找算法。通常应用在一些需要快速判断某个元素是否属于集合，但是并不严格要求100%正确的场合。


##### Bloom filter 特点

为了说明Bloom Filter存在的重要意义，举一个实例：假设要你写一个网络蜘蛛（web crawler）。由于网络间的链接错综复杂，蜘蛛在网络间爬行很可能会形成“环”。为了避免形成“环”，就需要知道蜘蛛已经访问过那些URL。给一个URL，怎样知道蜘蛛是否已经访问过呢？稍微想想，就会有如下几种方案：

1. 将访问过的URL保存到数据库。
2. 用HashSet将访问过的URL保存起来。那只需接近O(1)的代价就可以查到一个URL是否被访问过了。
3. URL经过MD5或SHA-1等单向哈希后再保存到HashSet或数据库。
4. BitMap方法。建立一个BitSet，将每个URL经过一个哈希函数映射到某一位。

方法1~3都是将访问过的URL完整保存，方法4则只标记URL的一个映射位。以上方法在数据量较小的情况下都能完美解决问题，但是当数据量变得非常庞大时问题就来了。

方法1的缺点：数据量变得非常庞大后关系型数据库查询的效率会变得很低。而且每来一个URL就启动一次数据库查询是不是太小题大做了？  
方法2的缺点：太消耗内存。随着URL的增多，占用的内存会越来越多。就算只有1亿个URL，每个URL只算50个字符，就需要5GB内存。  
方法3：由于字符串经过MD5处理后的信息摘要长度只有128Bit，SHA-1处理后也只有160Bit，因此方法3比方法2节省了好几倍的内存。  
方法4消耗内存是相对较少的，但缺点是单一哈希函数发生冲突的概率太高。还记得数据结构课上学过的Hash表冲突的各种解决方法么？若要降低冲突发生的概率到1%，就要将BitSet的长度设置为URL个数的100倍。 

实质上上面的算法都忽略了一个重要的隐含条件：允许小概率的出错，不一定要100%准确！也就是说少量url实际上没有没网络蜘蛛访问，而将它们错判为已访问的代价是很小的——大不了少抓几个网页呗。 


##### Bloom filter 算法

Bloom filter可以看做是对bitmap的扩展。只是使用多个hash映射函数，从而减低hash发生冲突的概率。算法如下:

1. 创建 m 位的bitset，初始化为0， 选中k个不同的哈希函数
2. 第 i 个hash 函数对字符串str 哈希的结果记为 h(i,str) ,范围是（0，m-1）
3. 将字符串记录到bitset的过程：对于一个字符串str,分别记录h(1,str),h(2,str)...,h(k,str)。 然后将bitset的h(1,str),h(2,str)...,h(k,str)位置1。也就是将一个str映射到bitset的 k 个二进制位。

4. 检查字符串是否存在:对于字符串str，分别计算h(1，str)、h(2，str),...,h(k，str)。然后检查BitSet的第h(1，str)、h(2，str),...,h(k，str) 位是否为1，若其中任何一位不为1则可以判定str一定没有被记录过。若全部位都是1，则“认为”字符串str存在。但是若一个字符串对应的Bit全为1，实际上是不能100%的肯定该字符串被Bloom Filter记录过的。（因为有可能该字符串的所有位都刚好是被其他字符串所对应）这种将该字符串划分错的情况，称为false positive 。

5. 删除字符串:字符串加入了就被不能删除了，因为删除会影响到其他字符串。实在需要删除字符串的可以使用Counting bloomfilter(CBF)。


`Bloom Filter 使用了k个哈希函数，每个字符串跟k个bit对应。从而降低了冲突的概率。`



##### 最优的哈希函数个数，位数组m大小

哈希函数的选择对性能的影响应该是很大的，一个好的哈希函数要能近似等概率的将字符串映射到各个Bit。选择k个不同的哈希函数比较麻烦，一种简单的方法是选择一个哈希函数，然后送入k个不同的参数。

在原始个数位n时，那这里的k应该取多少呢？位数组m大小应该取多少呢？这里有个计算公式:`k=(ln2)*(m/n)`, 当满足这个条件时，错误率最小。


假设错误率为0.01， 此时m 大概是 n 的13倍，k大概是8个。 这里的n是元素记录的个数，m是bit位个数。如果每个元素的长度原大于13，使用Bloom Filter就可以节省内存。


##### 错误率估计



##### 实现示例

```
#define SIZE 15*1024*1024
char a[SIZE]; /* 15MB*8 = 120M bit空间 */
memset(a,0,SIZE);

int seeds[] = { 5, 7, 11, 13, 31, 37, 61};

int hashcode(int cap,int seed, string key){
	int hash = 0;
	for (int i=0;i<key.length();i++){
		hash = (seed*hash +key.charAt(i));
	}
	return hash & (cap-1);
}
```

对每个字符串str求哈希就可以使用 `hashcode(SIZE*8,seeds[i],str)` ,i 的取值范围就是 （0，k）。


##### Bloom filter应用 

* 拼写检查一类的字典应用
* 数据库系统
* 网络领域（爬虫，web cache sharing）


##### 参考  
http://www.cnblogs.com/heaad/archive/2011/01/02/1924195.html
http://blog.csdn.net/jiaomeng/article/details/1495500  
http://pages.cs.wisc.edu/~cao/papers/summary-cache/node8.html  `哈希函数个数k、位数组大小m` 测试论证


### Trie树

字典树，英文名Trie树，Trie一词来自retrieve，发音为/tri:/ “tree”，也有人读为/traɪ/ “try”，
又称单词查找树，Trie树，是一种树形结构（多叉树）。

trie，又称为前缀树或字典树，是一种有序树，用于保存关联数组。

##### trie基本

1. 除根节点不包含字符，每个节点都包含一个字符
2. 从根节点到某一个节点，路径上经过的字符连接起来，为该节点对应的字符串
3. 每个节点的所有子节点包含的字符都不相同（保证每个节点对应的字符串都不一样）

比如：

```
                    / \    
                   / | \
                  t  a  i                
                /  \     \
               o    e     n
                   /|\    /
                  a d n  n                
```

上面的Trie树，可以表示字符串集合{“a”, “to”, “tea”, “ted”, “ten”, “i”, “in”, “inn”} 。

trie树把每个关键字保存在一条路径上，而不是一个节点中  
两个有公共前缀的关键字，在Trie树中前缀部分的路径相同，所以Trie树又叫做前缀树（Prefix Tree）。  


##### trie树存储结构和基本操作

最简单实现 ---- 26个字母表 a-z (没有考虑数字，大小写，其他字符如=-*/)

子树用数组存储，浪费空间；如果系统中存在大量字符串，且这些字符串基本没有公共前缀，trie树将消耗大量内存  
如果用链表存储，查询时需要遍历链表，查询效率有所降低  

```
define ALPHABET_NUM 26
typedef struct trie_node{
   char value;
   bool isKey;/*是否代表一个关键字*/
   int count; /*可用于词频统计，表示关键字出现的次数*/
   struct Node *subTries[ALPHABET];
}*Trie

Trie Trie_create();
int Trie_insert(Trie trie,char *word); // 插入一个单词
int Trie_search(Trie trie,char *word);// 查找一个单词
int Trie_delete(Trie trie,char *word);// 删除一个单词

Trie Trie_create(){
    trie_node* pNode = new trie_node();
    pNode->count = 0;
    for(int i=0; i<ALPHABET_SIZE; ++i)
        pNode->children[i] = NULL;
    return pNode;
}

void trie_insert(trie root, char* key)
{
    trie_node* node = root;
    char* p = key;
    while(*p)
    {
        if(node->children[*p-'a'] == NULL)
        {
            node->children[*p-'a'] = create_trie_node();
        }
        node = node->children[*p-'a'];
        ++p;
    }
    node->count += 1;
}

/**
 * 查询：不存在返回0，存在返回出现的次数
 */ 
int trie_search(trie root, char* key)
{
    trie_node* node = root;
    char* p = key;
    while(*p && node!=NULL)
    {
        node = node->children[*p-'a'];
        ++p;
    }
    
    if(node == NULL)
        return 0;
    else
        return node->count;
}

```

trie树的增加和删除都比较麻烦，但索引本身就是写少读多，是否考虑添加删除的复杂度上升，依靠具体场景决定。  


##### trie 问题

它的优点是： 

1. 插入和查询的效率很高，都是O(m),其中 m 是待插入/查询的字符串的长度
2. Trie树可以对关键字按字典序排序  
3. 利用字符串的公共前缀来最大限度地减少无谓的字符串比较,提高查询效率

缺点：

1. trie 树比较费内存空间，在处理大数据时会内存吃紧
2. 当hash函数较好时，Hash查询效率比 trie 更优

[知乎这里](http://www.zhihu.com/question/27168319)有个问题：`10万个串找给定的串是否存在`, 对trie和hash两种方案给出了讨论。 


[DATrie](https://github.com/kmike/datrie) 是使用python实现的双数组trie树， 双数组可以减少内存的使用量  。有关 double-array trie，可以参考[这篇论文](http://linux.thai.net/~thep/datrie/datrie.html)
  

##### trie应用

典型应用是：前缀查询,字符串查询，排序  
  
* 用于统计，排序和保存大量的字符串（但不仅限于字符串）  
* 经常被搜索引擎系统用于文本词频统计  
* 排序大量字符串   
* 用于索引结构  
* 敏感词过滤


### 数据库索引




### 倒排索引(Inverted index)

也叫反向索引。是文档检索系统中最常用的数据结构。

常规的索引是文档到关键词的映射，如果对应的文档是



[Elasticsearch](https://github.com/elastic/elasticsearch)就是使用倒排索引(inverted index)的结构来做快速的全文搜索。ElasticSearch 不仅用于全文搜索, 还有非常强大的统计功能 (facets)。

携程，58，美团的分享中都提到ES构建实时日志系统，帮助定位系统问题。


http://es.xiaoleilu.com/index.html

### 双层桶划分




### 外排序



### 分布处理之Mapreduce



### Hadoop














