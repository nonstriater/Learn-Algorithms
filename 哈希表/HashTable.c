
#include "stdio.h"



typedef char * Key;
typedef int Value;
typedef unsigned int Hash;



typedef struct Entry
{
	struct Entry *next;
	Hash hash;  // key 对应的hash值
	Key key;
	Value value;
}Entry;


//  拉链法实现，也就是链表的数组.也是 数组和链表优势的结合
typedef struct HashTable{

	Entry **head;

	unsigned int size;
	unsigned int usage;

}HashTable;


HashTable *create(unsigned int);
HashTable *put(HashTable *,Key,Value);
HashTable *putInHeads(HashTable *,Key,Value); // 数组 
HashTable *putInLists(HashTable *,Key,Value); // 链表 
Value find(HashTable *,Key );
HashTable*delete(HashTable *,Key );
void print(HashTable *);

Hash hashCode(Key);  // 哈希函数



HashTable *create(unsigned int size){

	HashTable *hashTable = malloc(sizeof(HashTable));
	if(hashTable==NULL){
		printf("malloc error\n");
		return NULL;
	}

	hashTable->size=size;
	hashTable->usage = 0;
	hashTable->head = calloc(size,sizeof(Entry *));

	return hashTable;
}


HashTable *put(HashTable *hashTable,Key key,Value value){

	if (key==NULL)
	{
		return hashTable;
	}



}

Value find(HashTable *hashTable,Key key){


}

void print(HashTable *hashTable){

	Entry *entry;
	for (int i = 0; i < hashTable->size; ++i)
	{
		entry = hashTable->head[i];
		while(entry!=NULL){
			printf("%s=%d\n",entry->key,entry->value);
			entry=entry->next;
		}
	}

}


// ?????
Hash hashCode(char *key){

	int offset = 5;
	Hash hashCode = 0;
	while(*key){
		hashCode = (hashCode << offset) + (*key++);
	}

	return hashCode;

}


int main(){



	return 0;
}

