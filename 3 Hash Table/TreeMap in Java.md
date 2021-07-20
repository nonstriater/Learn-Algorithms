# TreeMap in Java


java 中 TreeMap的实现原理。



#### 特点

* 有序的Key-value 集合，通过红黑树实现；
* 遍历时元素按照键key的自然顺序进行排序，也可以创建映射时提供的 Comparator 进行排序，具体取决于使用的构造方法
* TreeMap的基本操作 containsKey、get、put 和 remove 的时间复杂度是 log(n)



#### 引用场景

* 一致性Hash算法 



## 使用

```
//创建TreeMap对象：
TreeMap<String,Integer> treeMap = new TreeMap<String,Integer>();

		//新增元素:
        treeMap.put("hello",1);
        treeMap.put("world",2);
        treeMap.put("my",3);
        treeMap.put("name",4);


//遍历元素， 按照key排序
        Set<Map.Entry<String,Integer>> entrySet = treeMap.entrySet();
        for(Map.Entry<String,Integer> entry : entrySet){
            String key = entry.getKey();
            Integer value = entry.getValue();
            System.out.println("TreeMap元素的key:"+key+",value:"+value);
        }

String firstKey = treeMap.firstKey();//获取集合内第一个元素

String lastKey =treeMap.lastKey();//获取集合内最后一个元素

String lowerKey =treeMap.lowerKey("jiaboyan");//获取集合内的key小于"jiaboyan"的第一个key

String ceilingKey =treeMap.ceilingKey("jiaboyan");//获取集合内的key大于等于"jiaboyan"的第一个key        

```

## 原理


参考 [红黑树](../Tree/9-红黑树\ R-B\ tree/红黑树.md)


## 应用



### 一致性Hash算法 

一致性Hash算法解决的问题是:  数据均匀的分片存储在不同的机器节点上，且在机器节点上发送增删时 (扩容或者缩容时) ，最少数据集的映射(rehash) 规则发生改变。

简单说下原理：

treeMap 中 key 是 机器节点node 的 hash值， value 是机器节点 IP:port  ； 使用TreeMap的  ceilingKey(hash) 这个 API 可以获得   第一个大于 这个 hash值的 节点

```
public class Demo {

    private static String[] servers = {“ip1”, “1p2”, “ip3"};

    private TreeMap treeMap; //

    /* 一个数据key，会被分片到哪个机器上 */
    public String shardingServer(String key) {
        
        int  dataHash = hash(key);

        //怎么找大于 data_hash 值 的第一个节点？  借助 TreeMap 结构
        String node = getServer(dataHash)
        
        return node;
    }

    /* hash 函数*/
    public int hash(String key){

    }

    //寻找第一个大于 hash 值的 node
    private String getServer(String hash) {
        
        return treeMap.ceilingKey(hash)
    }

}
```






