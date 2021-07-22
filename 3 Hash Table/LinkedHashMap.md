# LinkedHashMap

java 中 LinkedHashmap的实现原理。LinkedHashmap继承自 HashMap。 

HashMap是无序的，迭代访问顺序并不一定与插入(put)顺序一致。 迭代顺序与插入顺序一致，这种叫做 插入有序。

#### 特点

* 维护一个所有entry的双向链表
* 构造函数 有一个 accessOrder 参数，控制访问顺序 （插入顺序 和 访问顺序）； 其中，访问顺序比较适合做 LRU 缓存


#### 引用场景

* LUR 缓存 (最近最少使用)


## 原理


```
public class LinkedHashMap<K,V>
    extends HashMap<K,V>
    implements Map<K,V> {

    	static class Entry<K,V> extends HashMap.Node<K,V> {
        	Entry<K,V> before, after;
        	Entry(int hash, K key, V value, Node<K,V> next) {
            	super(hash, key, value, next);
        	}
    	}	

    	transient LinkedHashMap.Entry<K,V> head;

    	transient LinkedHashMap.Entry<K,V> tail;

    }
```


## 用LinkedHashMap实现LRU


构造函数如下

```
public LinkedHashMap(int initialCapacity,
                         float loadFactor,
                         boolean accessOrder) {
        super(initialCapacity, loadFactor);
        this.accessOrder = accessOrder;
    }
```

accessOrder 是访问顺序，默认为插入顺序（false）, true 代表访问顺序。


访问顺序的意思是，当有一个entry被访问以后，这个entry就被移动到链表的表尾。  这个特性非常适合 LRU 缓存 (最近最少使用) ;

插入逻辑，运行自定义删除最老entry的逻辑

```
void afterNodeInsertion(boolean evict) { // possibly remove eldest
        LinkedHashMap.Entry<K,V> first;
        if (evict && (first = head) != null && removeEldestEntry(first)) {
            K key = first.key;
            removeNode(hash(key), key, null, false, true);
        }
}
```


重写此方法，维持此映射只保存100个条目的稳定状态，在每次添加新条目时删除最旧的条目。

```
private static final int MAX_ENTRIES = 100;  
protected boolean removeEldestEntry(Map.Entry eldest) {  
    return size() > MAX_ENTRIES;  
} 
```








