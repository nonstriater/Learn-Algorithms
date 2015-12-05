

## 二叉查找树

二叉查找树（Binary search tree），也叫`有序二叉树(Ordered binary tree)`,`排序二叉树(Sorted binary tree)`。是指一个空树或者具有下列性质的二叉树：
 
 1. 若任意节点的左子树不为空，则左子树上所有的节点值小于它的根节点值
 2. 若任意节点的右子树不为空，则右子树上所有节点的值均大于它的根节点的值
 3. 任意节点左右子树也为二叉查找树
 4. 没有键值相等的节点

    ```
    typedef int ElemType;
    typedef struct BiSearchTree{
        ElemType key;
        struct BiSearchTree *lChild;
        struct BiSearchTree *rChild;
    }BiSearchTree;
    BiSearchTree *bisearch_tree_insert(BiSearchTree *tree,ElemType node);
    int bisearch_tree_delete(BiSearchTree **tree,ElemType node);
    int bisearch_tree_search(BiSearchTree *tree,ElemType node);
    ```


删除节点,需要重建排序树

 1) 删除节点是叶子节点（分支为0），结构不破坏  
 2）删除节点只有一个分支(分支为1)，结构也不破坏  
 3）删除节点有2个分支，此时删除节点   
 
思路一： 选左子树的最大节点，或右子树最小节点替换  
 
``` 
int bisearch_tree_delete(BiSearchTree **tree,ElemType node){
    
    if (NULL==tree) {
        return -1;
    } 
    // 查找删除目标节点
    BiSearchTree *target=*tree,*parent=NULL;
    while (NULL!=target) {
        if (node<target->key) {
            parent=target;
            target=target->lChild;
        }else if(node==target->key){
            break;
        }else{
            parent=target;
            target=target->rChild;
        }
    }
    
    if (NULL==target) {
        printf("树为空，或想要删除的节点不存在\n");
        return -1;
    }
    //该节点为叶子节点，直接删除
    if (!target->rChild && !target->lChild)
    {
        if (NULL==parent) {////只有一个节点的二叉查找树
            *tree=NULL;
        }else{
            if (target->key>parent->key) {
                parent->rChild=NULL;
            }else{
                parent->lChild=NULL;
            }
            
        }
        free(target);//父节点处理，不然野指针,造成崩溃
    }
    
    else if(!target->rChild){   //右子树空则只需重接它的左子树,用左子树替换掉当前要删除的节点
        BiSearchTree *del=target->lChild;
        target->key = target->lChild->key;
        target->lChild=target->lChild->lChild;
        target->rChild=target->lChild->rChild;
        
        free(del);
    }
    else if(!target->lChild){   //左子树空只需重接它的右子树
        BiSearchTree *del=target->rChild;
        target->key = target->rChild->key;
        target->lChild=target->rChild->lChild;
        target->rChild=target->rChild->rChild;
        
        free(del);
    }
    else{   //左右子树均不空，p，t 2个指针一前以后，将左子树最大的节点(肯定是一个最右的节点)替换到删除的节点后，还需要处理左子树最大节点的左子树
        
        BiSearchTree *p=target,*t=target->lChild;
        while (t->rChild) {
            p = t;
            t=t->rChild;
        }// 找到左子树最大的，是删除节点的直接“前驱”
        
        target->key = t->key;
        
        if (p!=target) {
            p->rChild = t->lChild;
        }else{
            target->lChild = t->lChild;
        }
        
        free(t);
    }
        return 0;
    }
```


## 伸展树 (splay tree)

伸展树是一种自平衡的二叉排序树。为什么需要这些自平衡的二叉排序树？

n个节点的完全二叉树，其查找，删除的复杂度都是O(logN),但是如果频繁的插入删除，导致二叉树退化成一个n个节点的单链表，也就是`插入，查找复杂度趋于O(N)`，为了克服这个缺点，出现了很多二叉查找树的变形，如AVL树，红黑树，以及接下来介绍的 伸展树(splay tree)。




## AVL树


## 红黑树



## B树

平衡查找树，一种多路查找树。

能保证数据插入和删除情况下，任然保持执行效率。

一个M阶的B树满足：

1. 每个节点最多M个子节点
2. 除跟节点和叶节点外，其它每个节点至少有M/2个孩子
3. 根节点至少2个节点
4. 所有叶节点在同一层，叶节点不包含任何关键字信息
5. 有k个关键字的页节点包含k+1个孩子

也就是说：
根节点到每个叶节点的路径长度都是相同的。


## B+树



mysql索引使用B+树的数据结构

## B*树



## R树





## Treap 树




## 赫夫曼编码 Huffman

这是一个经典的压缩算法。通过`字符出现的频率`，`优先级`，`二叉树`进行的压缩算法。

对一个字符串，计算每个字符出现的次数,把这些字符放到优先队列（priority queue）
这这个priority queue转出二叉树

需要一个字符编码表来解码,通过二叉树建立huffman编码和解码的字典表


原始串：
二级制编码：
huffman编码：


###存储结构和基本操作

```
struct node{
    char *huffCode; // 叶子节点的huff编码
    int weight;
    struct node *left,right;
}
```

###构建赫夫曼树

原则：出现频率越多的会在越上层，编码也越短，出现频率越少的在越下层，编码也越长。
不存在某一个编码是另一个编码的前缀,字符都在叶节点上，所以不会存在一个编码是另一个编码的前缀
二叉树每个节点要么是叶子节点，要么是双分支节点(且左分支编码为0，右分支编码为1)


###压缩

1. 扫描输入文件，统计各个字符出现的次数，对结构排序 （hash统计每个字符出现的次数）
2. 根据排序结构，构建赫夫曼树 （贪心策略，每次选频率值最低的2个节点合并,需要优先队列帮组(priority queue，又叫最小堆)）
3. 对树进行遍历（左分支编码为0，右分支编码为1），得到各个字符的huffman编码，存到hash表中（这个就是编解码表，也可直接存储到节点中，如上面的char *huffCode）
4. 重新对文件扫描，根据hash表进行压缩

压缩的文件为了能够解压缩，需要一个文件头，用来重建赫夫曼树，包括：  
被编码的文本长度 unsigned int size  
字符频率表  unsigned char freqs[NUM_CHARS]  

###解压缩

1. 读取文件头  
2. 遍历编码后的bits,从赫夫曼树的根节点出发，遇到0，进入左子树，遇到1进入右子树，直到叶节点  
  




## 字典树trie(前缀树，单词查找树)

### trie基本

字典树，英文名Trie树，Trie一词来自retrieve，发音为/tri:/ “tree”，也有人读为/traɪ/ “try”，
又称单词查找树，Trie树，是一种树形结构（多叉树）。

trie，又称为前缀树或字典树，是一种有序树，用于保存关联数组。

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


### trie树存储结构和基本操作

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


### trie 问题

它的优点是： 

1. 插入和查询的效率很高，都是O(m),其中 m 是待插入/查询的字符串的长度
2. Trie树可以对关键字按字典序排序  
3. 利用字符串的公共前缀来最大限度地减少无谓的字符串比较,提高查询效率

缺点：

1. trie 树比较费内存空间，在处理大数据时会内存吃紧
2. 当hash函数较好时，Hash查询效率比 trie 更优

[知乎这里](http://www.zhihu.com/question/27168319)有个问题：`10万个串找给定的串是否存在`, 对trie和hash两种方案给出了讨论。 


[DATrie](https://github.com/kmike/datrie) 是使用python实现的双数组trie树， 双数组可以减少内存的使用量  。有关 double-array trie，可以参考[这篇论文](http://linux.thai.net/~thep/datrie/datrie.html)
  

### trie应用

典型应用是：前缀查询,字符串查询，排序  
  
* 用于统计，排序和保存大量的字符串（但不仅限于字符串）  
* 经常被搜索引擎系统用于文本词频统计  
* 排序大量字符串   
* 用于索引结构  
* 敏感词过滤  

### 实际应用问题  

1. 给你100000个长度不超过10的单词。对于每一个单词，我们要判断他出没出现过，如果出现了，求第一次出现在第几个位置  
分析思路一：trie树 ，找到这个字符串查询操作就可以了，如何知道出现的第一个位置呢？我们可以在trie树中加一个字段来记录当前字符串第一次出现的位置。  

2. 已知n个由小写字母构成的平均长度为10的单词,判断其中是否存在某个串为另一个串的前缀子串 
  
3. 给出N 个单词组成的熟词表，以及一篇全用小写英文书写的文章，请你按最早出现的顺序写出所有不在熟词表中的生词。  
分析：trie树查询单词的应用。先建立N个熟词的前缀树，然后按文章的单词一次查询。  
  
4. 给出一个词典，其中的单词为不良单词。单词均为小写字母。再给出一段文本，文本的每一行也由小写字母构成。判断文本中是否含有任何不良单词。例如，若rob是不良单词，那么文本problem含有不良单词。
分析：先用不良单词建立trie树，然后过滤文本(每个单词都在trie树上查询，查询的复杂度O(1),效率非常高)，这正是`敏感词过滤系统(或垃圾评论系统)`的原理。  
  
5. 给你N 个互不相同的仅由一个单词构成的英文名，让你将它们按字典序从小到大排序输出
分析：这是trie树排序的典型应用，建立N个单词的trie树，然后线序遍历整个树，就可以达到效果。  


  
## 后缀树（suffix tree）

###后缀树的应用

可以解决很多字符串的问题

1. 查找字符串S1是否在字符串S中
2. 指定字符串S1在字符串S中出现的次数
3. 字符串S中的最长重复子串
4. 2个字符串的最长公共部分







