
/*

### trie基本

字典树，英文名Trie树，Trie一词来自retrieve，发音为/tri:/ “tree”，也有人读为/traɪ/ “try”，
又称单词查找树，Trie树，是一种树形结构。

trie，又称为前缀树或字典树，是一种有序树，用于保存关联数组。

1） 一个节点的所有子孙都有相同的前缀，即为这个节点对应的字符串
2） 根节点对应空字符串，即不包含字符
3） 不是所有节点都有对应值，只有叶子节点和部分内部节点所对应的键才有相关的值
4） 键不是保存在节点中，而是由节点在树中的位置决定。


### trie应用

典型应用是：

用于统计，排序和保存大量的字符串（但不仅限于字符串），
所以经常被搜索引擎系统用于文本词频统计。
排序大量字符串
用于索引结构
敏感词过滤


它的优点是：
节省空间:利用字符串的公共前缀来节约存储空间
最大限度地减少无谓的字符串比较




查询效率比hash table 更优？？



### trie 存储结构设计 

 最简单实现 ---- 26个字母表 a-z 。

子树用数组存储，浪费空间；
如果用链表存储，查询时需要遍历链表，降低查询效率



DATrie  libdatrie

double-array trie 
参考作者的这篇论文 http://linux.thai.net/~thep/datrie/datrie.html


trie树的增加和删除都比较麻烦，但索引本身就是写少读多，是否考虑添加删除的复杂度上升，依靠具体场景决定
 


### trie 问题

 中文支持 


*/


#include <stdio.h>
#include <stdlib.h>

#define  ALPHABET_SIZE 26

typedef struct node
{
  int count;  //count 如果为0，则代表非黄色点，count>0代表是黄色点，同时表示出现次数;
  char value; //字符
  struct node * subtries[ALPHABET_SIZE]; //子树
} *Trie;


//插入字符串，建立字典树. 返回值 < 0 表示插入失败
int trie_insert(Trie *trie,char *c){

	if (NULL==trie)
	{
		*trie = (Trie)malloc(sizeof(struct node));
		if (NULL==trie)
		{
			printf("malloc failure...\n");
		}
	}

	char *p = c;
	while(*p!='\0'){
		if (*p)
		{
			/* code */
		}

		p++;
	}


}


// 字符串查找，返回值<0表示没有查找到
int trie_query(Trie *trie,char *c){


}


//
void trie_remove(){}




int main(){

	Trie trie = NULL;
	char *dict[10]={"int","integer","float","char","nonstriater","weibo"};
	for (int i = 0; i < sizeof(dict)/sizeof(int); ++i)
	{
		if (trie_insert(&trie,dict[i])<0)
		{
			printf("%s 插入失败\n", dict[i]);
		}
		
	}

	// 查询cha
	printf("查询cha \n");

	// 查询char
	printf("查询char \n");

	// 查询hello
	printf("查询hello \n");


	return 0;	
}













