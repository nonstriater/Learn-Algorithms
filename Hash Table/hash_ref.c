#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

#define DEFAULT_MAP_SIZE 1<<5
#define MAX_MAP_SIZE 1<<30
#define CAPACITY_FACTOR 0.6f
#define MAX_KEY_LENGTH 1<<3

typedef unsigned int Hash;
typedef char* Key;
typedef int Value;
typedef struct Entry{
    struct Entry *next;
    Hash hash;
    Value value;
    Key key;
}Entry;

typedef struct HashMap{
    Entry** heads;
    Value nul;
    unsigned int size;
    unsigned int usage;
    unsigned int realCapacity; //size * CAPACITY_FACTOR
    unsigned int sizeForIndex; //size - 1
}HashMap;

HashMap* create(unsigned int);
HashMap* transfer(HashMap*, HashMap*);
Hash hash(char[]);
HashMap* put(HashMap*, Key, Value);
HashMap* putInHeads(HashMap*, int, Hash, Key, Value);
HashMap* putInList(HashMap*, int, Hash, Key, Value);
HashMap* resize(HashMap*);
int find(char[]);
void print(HashMap*);

HashMap* create(unsigned int size){
    HashMap* hashMap = malloc(sizeof(HashMap));
    int i;
    hashMap->size = size;
    hashMap->sizeForIndex = size - 1;
    hashMap->realCapacity = (unsigned int)(size * CAPACITY_FACTOR);
    hashMap->usage = 0;
    hashMap->heads = calloc(size, sizeof(Entry*));
    hashMap->nul = 0;
    return hashMap;
}

HashMap* transfer(HashMap* newHashMap, HashMap* oldHashMap){
    unsigned int oldIndex, newIndex;
    Entry *oldEntry, *oldNextEntry;
    for (oldIndex = 0; oldIndex < oldHashMap->size; oldIndex++){
        if (oldHashMap->heads[oldIndex] != NULL){
            oldEntry = oldHashMap->heads[oldIndex];
            do{
                newIndex = (oldEntry->hash) & (newHashMap->sizeForIndex);
                oldNextEntry = oldEntry->next;
                oldEntry->next = newHashMap->heads[newIndex];
                newHashMap->heads[newIndex] = oldEntry;
                oldEntry = oldNextEntry;
            } while (oldEntry != NULL);
        }
    }
    newHashMap->usage = oldHashMap->usage;
    newHashMap->nul = oldHashMap->nul;
    free(oldHashMap->heads);
    oldHashMap->heads = NULL;
    free(oldHashMap);
    oldHashMap = NULL;
    return newHashMap;
}

Hash hashCode(char* key){
    int offset = 5;
    Hash hashCode = 0;
    while (*key) hashCode = (hashCode << offset) + (*key++);
    return hashCode;
}

HashMap* put(HashMap* hashMap, Key key, Value value){
    if (key == NULL){ 
        hashMap->nul = value; 
        return hashMap;
    }
    Hash hash = hashCode(key);
    int index = hash & (hashMap->sizeForIndex);
    
    if (hashMap->heads[index] == NULL){
        return putInHeads(hashMap, index, hash, key, value);
    } else {
        return putInList(hashMap, index, hash, key, value);
    }
}

HashMap* putInHeads(HashMap* hashMap, int index, Hash hash, Key key, Value value){
    Entry* newHead = malloc(sizeof(Entry));
    newHead->hash = hash;
    newHead->key = _strdup(key);
    newHead->value = value;
    newHead->next = NULL;
    hashMap->heads[index] = newHead;
    (hashMap->usage)++;
    if (hashMap->usage > hashMap->realCapacity) return resize(hashMap);
    return hashMap;
}
HashMap* putInList(HashMap* hashMap, int index, Hash hash, Key key, Value value){
    Entry* lastEntry = hashMap->heads[index];
    while (lastEntry != NULL){
        if (lastEntry->hash == hash){
            lastEntry->value += value;
            return hashMap;
        }
        else lastEntry = lastEntry->next;
    }
    lastEntry = malloc(sizeof(Entry));
    lastEntry->hash = hash;
    lastEntry->key = _strdup(key);
    lastEntry->value = value;
    lastEntry->next = hashMap->heads[index];
    hashMap->heads[index] = lastEntry;
    (hashMap->usage)++;
    if (hashMap->usage > hashMap->realCapacity) return resize(hashMap);
    return hashMap;
}

HashMap* resize(HashMap* hashMap){
    HashMap* newHashMap;
    if ((hashMap->size << 1) <= MAX_MAP_SIZE) { 
        newHashMap = create((hashMap->size << 1));
        newHashMap = transfer(newHashMap, hashMap);
        return newHashMap;
    }
    return hashMap;
}

Value get(HashMap* hashMap, Key key){
    Hash hash = hashCode(key);
    int index = hash & (hashMap->sizeForIndex);
    Entry* entry = hashMap->heads[index];
    while (entry != NULL){
        if (entry->hash == hash) return entry->value;
        entry = entry->next;
    }
    return NULL;
}

void print(HashMap* hashMap){
    unsigned int i;
    Entry* entry;
    for (i = 0; i < hashMap->size; i++){
        entry = hashMap->heads[i];
        while (entry != NULL){
            printf("%s: %d\n", entry->key, entry->value);
            entry = entry->next;
        }
    }
}

int main(){
    clock_t start, end;
    HashMap* hashMap = create(DEFAULT_MAP_SIZE);
    FILE* fp;
    char filePath[0xFF];
    char line[5];
    char key[MAX_KEY_LENGTH];

    printf("input file path: ");
    scanf_s("%s", filePath, 0xFF);
    if (fopen_s(&fp, filePath, "r") == 0){
        start = clock();
        while (fgets(line, 5, fp) != NULL){
            line[3] = '\0';
            hashMap = put(hashMap, line, 1);
        }
        end = clock();
        printf("\n%fs", (float)(end - start)/1000);
        fclose(fp);
        print(hashMap);
    } else {
        printf("can't open file");
    }
    return 0;
 }