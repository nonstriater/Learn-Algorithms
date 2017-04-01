
/*
trie树
*/


#include <stdio.h>
#include <stdlib.h>

#define  ALPHABET_SIZE 26 // 256

typedef int  bool;
#define YES 1
#define NO 0

typedef struct node
{
  int count;  //count 如果为0，则代表非黄色点，count>0代表是黄色点，同时表示出现次数;
  char value; //字符
  struct node * subtries[ALPHABET_SIZE]; //子树
} Trie;



Trie *trie_create(Trie **trie){

	if (NULL==*trie)
	{
		*trie = (Trie *)malloc(sizeof(struct node));
		if (NULL==*trie)
		{
			printf("malloc failure...\n");
		}

		for (int i = 0; i < ALPHABET_SIZE; ++i)
		{
			(*trie)->subtries[i]=NULL;
		}
	}

	return *trie;

}


//插入字符串（插入一个单词），建立字典树. 返回值 < 0 表示插入失败
int trie_insert(Trie *trie,char *c){

	if (trie==NULL || c==NULL) // 对NULL指针解引用会崩溃
	{
		return -1;
	}

	char *p = c;
	Trie *temp = trie;
	while(*p != '\0'){
		
		if (temp->subtries==NULL)
		{
			//temp->subtries = (struct node *)malloc(sizeof(struct node)*ALPHABET_SIZE);
			if (temp->subtries==NULL)
			{
				return -1;
			}
		}

		if (temp->subtries[*p-'a']==NULL)
		{
			struct node *newNode = (struct node *)malloc(sizeof(struct node));
			if (!newNode)
			{
				printf("create new node fail \n");
				return -1;
			}
			newNode->value = *p;
			//newNode->subtries = NULL;
			temp->subtries[*p-'a'] = newNode;
		}

		
		temp = temp->subtries[*p-'a'];
		p++;

	}

	return 0;

}


// 字符串查找，返回值<0表示没有查找到
bool trie_query(Trie *trie,char *c){

	if (trie==NULL )
	{
		return NO;
	}

	char *p = c;
	Trie *temp = trie;
	bool ret=NO;
	if (temp->subtries == NULL)
	{
		return NO;
	}

	while (*p!='\0')
	{
		if (temp->subtries[*p-'a']!=NULL && temp->subtries[*p-'a']->value==*p)//匹配
		{
			temp = temp->subtries[*p-'a'];
			p++;
			continue;
		}
		
		break;
	}

	if (*p =='\0')
	{
		ret = YES;
	}

	return ret;

}


//
void trie_remove(){}




int main(){

	Trie *trie = NULL;
	if (!trie_create(&trie))
	{
		printf("trie init fail...\n");
	}

	char *dict[10]={"int","integer","float","char","nonstriater","weibo"};
	for (int i = 0; i < 6; ++i)
	{
		if (trie_insert(trie,dict[i])<0)
		{
			printf("%s 插入失败\n", dict[i]);
		}
		
	}

	// 查询cha
	printf("查询cha \n");
	if (trie_query(trie,"cha"))
	{
		printf("YES\n");
	}else{
		printf("NO\n");

	}

	// 查询char
	printf("查询char \n");
	if (trie_query(trie,"char"))
	{
		printf("YES\n");
	}else{
		printf("NO\n");

	}

	// 查询hello
	printf("查询hello \n");
	if (trie_query(trie,"hello"))
	{
		printf("YES\n");
	}else{
		printf("NO\n");

	}


	return 0;	
}













