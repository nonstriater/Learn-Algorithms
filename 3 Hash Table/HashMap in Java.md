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

    static class Node<K,V> implements Map.Entry<K,V> {
        final int hash;
        final K key;
        V value;
        Node<K,V> next;
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

}
```


## Hash冲突


## 扩容




## 问题









