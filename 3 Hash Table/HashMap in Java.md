# HashMap in Java

java 中 hashmap的实现原理。



## 数据结构

* HashMap底层实现, hashmap的存储结构和操作？
* hash冲突如何解决（链表和红黑树）？ 为什么hashmap中的链表需要转成红黑树？


好的哈希函数会尽可能地保证 计算简单和散列地址分布均匀,但是，再好的哈希函数也不能保证得到的存储地址绝对不发生冲突。



```
public class HashMap<K,V> extends AbstractMap<K,V>
    implements Map<K,V>, Cloneable, Serializable {

    transient int size; //当前元素个数

    int threshold; //扩容时机是： 当前容量大于等于 capacity * load factor    

    final float loadFactor; //默认 0.75 , 空间使用 75% 时开始扩容

    static final int TREEIFY_THRESHOLD = 8; //将链表转换为红黑树的阈值

    static final int UNTREEIFY_THRESHOLD = 6; //将红黑树转换为链表的阈值

    //1.7结构
    static class Node<K,V> implements Map.Entry<K,V> {
        final int hash;
        final K key;
        V value;
        Node<K,V> next;//链表结构
        ...
    }

    //1.8结构
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

table 在第一次put的时候初始化，length默认16， threshold 12 (0.75x16) ， 也就是第 13个 元素 put 的时候开始扩容

1.7 的实现是 数组+链表； 1.8 新增了红黑树，提高查询效率


### get(key) 方法

```
public V get(Object key) {
    Node<K,V> e;
    return (e = getNode(hash(key), key)) == null ? null : e.value;
}
final Node<K,V> getNode(int hash, Object key) {
    Node<K,V>[] tab; Node<K,V> first, e; int n; K k;
    if ((tab = table) != null && (n = tab.length) > 0 &&
        (first = tab[(n - 1) & hash]) != null) {
        if (first.hash == hash && // always check first node
            ((k = first.key) == key || (key != null && key.equals(k))))
            return first;
        if ((e = first.next) != null) {
            if (first instanceof TreeNode)//红黑树 查找
                return ((TreeNode<K,V>)first).getTreeNode(hash, key);
            do {//按照链表结构遍历查找
                if (e.hash == hash &&
                    ((k = e.key) == key || (key != null && key.equals(k))))
                    return e;
            } while ((e = e.next) != null);
        }
    }
    return null;
}

```


```
//计算hash值
//这是一个神奇的函数，用了很多的异或，移位等运算，对key的hashcode进一步进行计算以及二进制位的调整等来保证最终获取的存储位置尽量分布均匀
final int hash(Object k) {
        int h = hashSeed;
        if (0 != h && k instanceof String) {
            return sun.misc.Hashing.stringHash32((String) k);
        }

        h ^= k.hashCode();

        h ^= (h >>> 20) ^ (h >>> 12);
        return h ^ (h >>> 7) ^ (h >>> 4);
 }
```

### put(key, value) 方法


hash存储的过程是： key -> hashcode -> hash -> indexFor() 

```
public V put(K key, V value) {
    return putVal(hash(key), key, value, false, true);
}
    
    final V putVal(int hash, K key, V value, boolean onlyIfAbsent,
                   boolean evict) {

        Node<K,V>[] tab; Node<K,V> p; int n, i;
        if ((tab = table) == null || (n = tab.length) == 0)
            n = (tab = resize()).length;
        if ((p = tab[i = (n - 1) & hash]) == null)//当前桶为空，没有hash冲突
            tab[i] = newNode(hash, key, value, null);
        else {
            Node<K,V> e; K k;
            if (p.hash == hash &&
                ((k = p.key) == key || (key != null && key.equals(k))))//当前桶中的 key、key 的 hashcode 与写入的 key 相等
                e = p;
            else if (p instanceof TreeNode)//当前桶为红黑树，那按照红黑树的方式写入数据
                e = ((TreeNode<K,V>)p).putTreeVal(this, tab, hash, key, value);
            else {//链表，就需要将当前的 key、value 封装成一个新节点写入到当前桶的后面
                for (int binCount = 0; ; ++binCount) {
                    if ((e = p.next) == null) {
                        p.next = newNode(hash, key, value, null);
                        if (binCount >= TREEIFY_THRESHOLD - 1) // -1 for 1st
                            treeifyBin(tab, hash);//判断当前链表的大小是否大于预设的阈值，大于时就要转换为红黑树
                        break;
                    }
                    if (e.hash == hash &&
                        ((k = e.key) == key || (key != null && key.equals(k))))//在遍历过程中找到 key 相同时直接退出遍历
                        break;
                    p = e;
                }
            }
            if (e != null) { // existing mapping for key
                V oldValue = e.value;
                if (!onlyIfAbsent || oldValue == null)
                    e.value = value;
                afterNodeAccess(e);
                return oldValue;
            }
        }
        ++modCount;
        if (++size > threshold)//最后判断是否需要进行扩容
            resize();
        afterNodeInsertion(evict);
        return null;
    }

```


```
//返回数组下标
static int indexFor(int h, int length) {
        return h & (length-1);
}
```

这里用的位运行，而不是取模操作； 位运算性能更高。






## Hash冲突

HashMap是怎么处理hash碰撞的?

使用拉链法，为了提高链表查询效率，当桶对应的链表长度大于8的时候，转为红黑树。

## 扩容

初始化容量, 默认结果是 16

```
static final int DEFAULT_INITIAL_CAPACITY = 1 << 4; // aka 16， 为啥用位运算呢?直接写16不好么?
```

### 为什么需要扩容？

主要为缓解哈希冲突造成的外挂链表太长，造成查询性能低下。


### HashMap的扩容方式? 负载因子是多少? 扩容时机？什么时候会触发扩容？

HashMap 中 `final float loadFactor` ,  loadFactor 默认 0.75 , 也就是达到容量的 75%时就会开始扩容。

那么问题来了，扩容到多大？ 看 resize() 方法

```
final Node<K,V>[] resize() {
        Node<K,V>[] oldTab = table;
        int oldCap = (oldTab == null) ? 0 : oldTab.length;
        int oldThr = threshold;
        int newCap, newThr = 0;
        if (oldCap > 0) {
            if (oldCap >= MAXIMUM_CAPACITY) {
                threshold = Integer.MAX_VALUE;
                return oldTab;
            }
            else if ((newCap = oldCap << 1) < MAXIMUM_CAPACITY &&
                     oldCap >= DEFAULT_INITIAL_CAPACITY)
                newThr = oldThr << 1; // double threshold
        }
        else if (oldThr > 0) // initial capacity was placed in threshold
            newCap = oldThr;
        else {               // zero initial threshold signifies using defaults
            newCap = DEFAULT_INITIAL_CAPACITY;
            newThr = (int)(DEFAULT_LOAD_FACTOR * DEFAULT_INITIAL_CAPACITY);
        }
        if (newThr == 0) {
            float ft = (float)newCap * loadFactor;
            newThr = (newCap < MAXIMUM_CAPACITY && ft < (float)MAXIMUM_CAPACITY ?
                      (int)ft : Integer.MAX_VALUE);
        }
        threshold = newThr;

        //创建一个新的 newCap 大小的数组容器，调整table
        @SuppressWarnings({"rawtypes","unchecked"})
        Node<K,V>[] newTab = (Node<K,V>[])new Node[newCap];
        table = newTab;
        if (oldTab != null) {
            for (int j = 0; j < oldCap; ++j) {
                Node<K,V> e;
                if ((e = oldTab[j]) != null) {//有数据的桶才需要调整
                    oldTab[j] = null;
                    if (e.next == null)//没有链表结构
                        newTab[e.hash & (newCap - 1)] = e;
                    else if (e instanceof TreeNode)
                        ((TreeNode<K,V>)e).split(this, newTab, j, oldCap);
                    else { // preserve order
                        Node<K,V> loHead = null, loTail = null;
                        Node<K,V> hiHead = null, hiTail = null;
                        Node<K,V> next;
                        do {
                            next = e.next;
                            if ((e.hash & oldCap) == 0) {//hash值第 N+1 位是否为0
                                if (loTail == null)
                                    loHead = e;
                                else
                                    loTail.next = e;
                                loTail = e;
                            }
                            else {
                                if (hiTail == null)
                                    hiHead = e;
                                else
                                    hiTail.next = e;
                                hiTail = e;
                            }
                        } while ((e = next) != null);

                        if (loTail != null) {
                            loTail.next = null;
                            newTab[j] = loHead;
                        }
                        if (hiTail != null) {
                            hiTail.next = null;
                            newTab[j + oldCap] = hiHead;
                        }
                    }
                }
            }
        }
        return newTab;
    }
```

扩容到了2倍 `newThr = oldThr << 1; ` 



### 扩容后元素怎么重排到新的容器中，直接复制拷贝可以吗？ 

扩容会 rehash，复制数据等耗时操作。


* hashmap扩容时每个entry需要再计算一次hash吗？

不需要，但是需要重新调整桶的位置 `newTab[e.hash & (newCap - 1)] = e;`


* 扩容时避免rehash的优化 : cap 为 2 的次幂，rehash也是 cap * 2 ， 这样可以 `e.hash & (newCap - 1)` 计算时，有较少的 key 产生移动，hash值 高位 1 的 才需要移动




## 问题


### JDK7 和 8 HashMap 有什么区别？

* JDK8 实现引入红黑树，优化链表过长的查询效率
* 1.7 采用头插法，1.8采用尾插法； 解决多线程中出出现链表成环的问题 ； （hashmap本来就是非线程安全的，为啥要在多线程中使用hashmap）



### 链表上使用的头插还是尾插方式？

1.7 采用头插法，1.8采用尾插法； 解决多线程中出出现链表成环的问题


### 多线程下死循环问题


* hashmap扩容会引发什么问题，线上是否出现过类似的问题？如何避免扩容引发的问题？
* jdk1.8之前并发操作hashmap时为什么会有死循环的问题？

HashMap 在并发场景下，容易出现死循环

```
final HashMap<String, String> map = new HashMap<String, String>();
for (int i = 0; i < 1000; i++) {
    new Thread(new Runnable() {
        @Override
        public void run() {
            map.put(UUID.randomUUID().toString(), "");
        }
    }).start();
}
```

在 HashMap 扩容的时候会调用 resize() 方法，就是这里的并发操作容易在一个桶上形成环形链表；这样当获取一个不存在的 key 时，计算出的 index 正好是环形链表的下标就会出现死循环。程序临床反应就是 CPU 飙高， 这时候应该使用线程安全的HashMap，也就是 ConcurrentHashMap。




### hashmap的数组长度为什么要保证是2的幂？


https://bugs.java.com/bugdatabase/view_bug.do?bug_id=4631373 提出， 整数的除法（/）和 取模（%） 运算 性能比 位与操作(&) 慢10倍。


`h & (length-1)` 和 `h % length` 结果一样

举个例子
```
hashcode 311 对应的二进制是(1 0011 0111)
length 16  对应的二进制是(1 0000) ,  length-1 就是 （0 1111）

h & (length-1)` 就是取 hashcode 的低 4位

```

length 保持为 2 的幂， 那么length-1就会变成一个mask, 它会将hashcode低位取出来，hashcode的低位实际就是余数，和取余操作相比，与操作会将性能提升很多。

另外，hash扩容时 rehash 操作，只有 hash二进制 高位是 1 的hash key 需要 移动到新的 slot （pos + oldCap）, 高位是 0 的 key 不需要移动

![hashmap rehash](https://pic3.zhimg.com/80/v2-ed0ca17db342562dfc18434d12227be2_720w.jpg)



### 重写equals方法需同时重写hashCode方法


```
public static void main(String []args){
        HashMap<Person,String> map = new HashMap<Person, String>();
        Person person = new Person(1234,"乔峰");
        //put到hashmap中去
        map.put(person,"天龙八部");
        //get取出，从逻辑上讲应该能输出“天龙八部”
        System.out.println("结果:"+map.get(new Person(1234,"萧峰")));
}
```

hashCode()的默认行为是对堆上的对象产生独特值。因此 map.get(object) 的时候，不同的 object 的hashcode 不一样，自然结果就为null








