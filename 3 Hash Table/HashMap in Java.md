# HashMap in Java

java 中 hashmap的实现原理。


* HashMap底层实现, hashmap的存储结构和操作？
* hashmap的数组长度为什么要保证是2的幂？
* hash冲突如何解决（链表和红黑树）为什么hashmap中的链表需要转成红黑树？
* 扩容时机，什么时候会触发扩容？扩容时避免rehash的优化；
* hashmap扩容时每个entry需要再计算一次hash吗？
* hashmap扩容会引发什么问题，线上是否出现过类似的问题？如何避免扩容引发的问题？
* jdk1.8之前并发操作hashmap时为什么会有死循环的问题？


## 数据结构


```
public class HashMap<K,V> extends AbstractMap<K,V>
    implements Map<K,V>, Cloneable, Serializable {

    int threshold; //扩容 capacity * load factor    

    final float loadFactor; //默认 0.75    

    static class Node<K,V> implements Map.Entry<K,V> {
        final int hash;
        final K key;
        V value;
        Node<K,V> next;//链表结构
        ...
    }

    static final class TreeNode<K,V> extends LinkedHashMap.Entry<K,V> {
        TreeNode<K,V> parent;  // red-black tree links
        TreeNode<K,V> left;
        TreeNode<K,V> right;
        TreeNode<K,V> prev;    // needed to unlink next upon deletion
        boolean red;
    }

    public V put(K key, V value) {
        return putVal(hash(key), key, value, false, true);
    }

    public V get(Object key) {
        Node<K,V> e;
        return (e = getNode(hash(key), key)) == null ? null : e.value;
    }

    //hash 算法， 根据 key 的 hashCode() 计算而来
    static final int hash(Object key) {
        int h;
        return (key == null) ? 0 : (h = key.hashCode()) ^ (h >>> 16);
    }

}
```




## Hash冲突

HashMap是怎么处理hash碰撞的?



## 扩容

初始化容量, 默认结果是 16

```
static final int DEFAULT_INITIAL_CAPACITY = 1 << 4; // aka 16， 为啥用位运算呢?直接写16不好么?
```


HashMap的扩容方式? 负载因子是多少? 为什是这么多?

HashMap 中 `final float ` ,  loadFactor 默认 0.75 , 也就是达到容量的 75%时就会开始扩容。那么问题来了，扩容到多达？ 扩容后元素怎么重排到新的容器中，直接复制拷贝可以吗？




## 问题

### 链表上使用的头插还是尾插方式？


### 多线程下死循环问题







