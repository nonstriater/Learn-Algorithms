
# Bloom filter(布隆过滤器)

Bloom Filter是由Bloom在1970年提出的一种多哈希函数映射的快速查找算法。通常应用在海量数据处理中，一些需要快速判断某个元素是否属于集合，但是并不严格要求100%正确的场合（容忍错误的场景）。


## Bloom filter 特点

为了说明Bloom Filter存在的重要意义，举一个实例：假设要你写一个网络蜘蛛（web crawler）。由于网络间的链接错综复杂，蜘蛛在网络间爬行很可能会形成“环”。为了避免形成“环”，就需要知道蜘蛛已经访问过那些URL。给一个URL，怎样知道蜘蛛是否已经访问过呢？稍微想想，就会有如下几种方案：

1. 将访问过的URL保存到数据库。
2. 用HashSet将访问过的URL保存起来。那只需接近O(1)的代价就可以查到一个URL是否被访问过了。
3. URL经过MD5或SHA-1等单向哈希后再保存到HashSet或数据库。
4. BitMap方法。建立一个BitSet，将每个URL经过一个哈希函数映射到某一位。

方法1~3都是将访问过的URL完整保存，方法4则只标记URL的一个映射位。以上方法在数据量较小的情况下都能完美解决问题，但是当数据量变得非常庞大时问题就来了。

方法1的缺点：数据量变得非常庞大后关系型数据库查询的效率会变得很低。而且每来一个URL就启动一次数据库查询是不是太小题大做了？  
方法2的缺点：太消耗内存。随着URL的增多，占用的内存会越来越多。就算只有1亿个URL，每个URL只算50个字符，就需要5GB内存。  
方法3：由于字符串经过MD5处理后的信息摘要长度只有128Bit，SHA-1处理后也只有160Bit，因此方法3比方法2节省了好几倍的内存。  
方法4消耗内存是相对较少的，但缺点是单一哈希函数发生冲突的概率太高。还记得数据结构课上学过的Hash表冲突的各种解决方法么？若要降低冲突发生的概率到1%，就要将BitSet的长度设置为URL个数的100倍。 

实质上上面的算法都忽略了一个重要的隐含条件：允许小概率的出错，不一定要100%准确！也就是说少量url实际上没有没网络蜘蛛访问，而将它们错判为已访问的代价是很小的——大不了少抓几个网页呗。 


## 应用场景

* 爬虫对URL 去重，避免爬重复的URL; 爬虫Url重复（去重）：如果几个亿几十亿的url装在一个集合上 ，比较浪费空间，把url映射到布隆过滤器，纯新的url一定会爬取， 少部分(比如0.01%)被判断为重复url可能也是新url ，会缺掉一些网页而已。
* 垃圾邮箱问题，垃圾邮箱地址映射到bloomfilter，如果是垃圾邮箱，一定会被抓，这个能保证。无非是一些好人也被抓，这个可以通过给这些可伶的被误伤的设置个白名单就OK
* 避免缓存穿透，使用BloomFilter把所有数据放到bit数组中，当用户请求时存在的值肯定能放行，部分不存在的值也会被放行，绝大部分会被拦截。在DSP广告系统中，使用bloomfilter减少对Redis缓存读取，通过设备id读取用户信息( key为设备id，value hashmap 用户信息) ； 由于大量设备id都不是滴滴用户 (80%以上)，redis中都没有用户信息，因此会产生大量无效redis读取。使用BF可以减轻Redis读取压力。
* 减少磁盘IO： Google bigtable,  Apache HBase 使用 BloomFilter 防止不必要的磁盘IO
* 减少网络请求：相同请求拦截，防止被攻击，也就是去重

Redis 4.0 中通过 布隆过滤器插件 来支持，redis 布隆过滤器主要就两个命令：

* bf.add 添加元素到布隆过滤器中：bf.add urls https://jaychen.cc。
* bf.exists 判断某个元素是否在过滤器中：bf.exists urls https://jaychen.cc。


### 比特币 SPV钱包

比特币 SPV（simple payment verification）钱包应用中 使用 BloomFilter 加速钱包同步。

spv 主要用于移动支付的场景，不可能下载所有全节点数据，几百G

在2012年 BIP37之前，SPV的做法是将所有的区块和交易都下载下来，然后本地将不相关的交易给删掉。当然带来的问题就是同步慢、浪费带宽、增加内存使用。在BIP-37中就提到了因为这一点，导致用户对手机APP“Bitcoin Wallet”有所抱怨。


钱包余额多少？

* 保护隐私，SPV节点不用告诉相邻全节点自己的所有钱包地址，而只是说一个 可能存在于bloomfilter里的钱包地址集合
* 通过bloomfilter 过滤出 utxo，可能属于钱包地址，不在bloomfilter中地址对应的utxo一定会被过滤



## Bloom filter 算法


 Bloom filter   bitmap 数组 和  k个hash函数。

使用 bitmap 位图数据结构，本质是一个bit位数组， 用 一个 bit 位标记对应Value的 取值(0 or 1); 判断一个值是否存在，就是看对应的bitmap位是否为 1 

布隆过滤器还需要有 k 个哈希函数，进行如下操作：

* 使用 K 个哈希函数对元素值进行 K 次计算，得到 K 个哈希值。
* 根据得到的哈希值，在位数组中把对应下标的值置为 1。

比如有个url   https://jaychen.cc ，  有 3 个哈希函数：f1, f2, f3 和一个位数组 arr , 现在要把 url 插入布隆过滤器中：

* 对值进行三次哈希计算，得到三个值 n1, n2, n3。
* 把位数组中三个元素 arr[n1], arr[n2], arr[3] 置为 1。





现在需求是：要判断一个 url 是否在， 布隆过滤器中，对元素再次进行哈希计算，得到值之后判断位数组中的每个元素是否都为 1，如果值都为 1，那么说明这个值很大可能在布隆过滤器中；如果存在一个值不为 1，说明该元素肯定不在布隆过滤器中。

Scrapy-Redis的去重机制中，一个url指纹存储未 40长度的16 进制数，如27adcc2e8979cdee0c9cecbbe8bf8ff51edefb61
占用 20Byte内存空间，1亿个指纹占用2 GB



Bloom filter可以看做是对bitmap的扩展。只是使用多个hash映射函数，从而减低hash发生冲突的概率。算法如下:

1. 创建 m 位的bitset，初始化为0， 选中k个不同的哈希函数
2. 第 i 个hash 函数对字符串str 哈希的结果记为 h(i,str) ,范围是（0，m-1）
3. 将字符串记录到bitset的过程：对于一个字符串str,分别记录h(1,str),h(2,str)...,h(k,str)。 然后将bitset的h(1,str),h(2,str)...,h(k,str)位置1。也就是将一个str映射到bitset的 k 个二进制位。

4. 检查字符串是否存在:对于字符串str，分别计算h(1，str)、h(2，str),...,h(k，str)。然后检查BitSet的第h(1，str)、h(2，str),...,h(k，str) 位是否为1，若其中任何一位不为1则可以判定str一定没有被记录过。若全部位都是1，则“认为”字符串str存在。但是若一个字符串对应的Bit全为1，实际上是不能100%的肯定该字符串被Bloom Filter记录过的。（因为有可能该字符串的所有位都刚好是被其他字符串所对应）这种将该字符串划分错的情况，称为false positive 。

5. 删除字符串:字符串加入了就被不能删除了，因为删除会影响到其他字符串。实在需要删除字符串的可以使用Counting bloomfilter(CBF)。


`Bloom Filter 使用了k个哈希函数，每个字符串跟k个bit对应。从而降低了冲突的概率。`



### 最优的哈希函数个数，位数组m大小

哈希函数的选择对性能的影响应该是很大的，一个好的哈希函数要能近似等概率的将字符串映射到各个Bit。选择k个不同的哈希函数比较麻烦，一种简单的方法是选择一个哈希函数，然后送入k个不同的参数。

在原始个数位n时，那这里的k应该取多少呢？位数组m大小应该取多少呢？这里有个计算公式:`k=(ln2)*(m/n)`, 当满足这个条件时，错误率最小。


假设错误率为0.01， 此时m 大概是 n 的13倍，k大概是8个。 这里的n是元素记录的个数，m是bit位个数。如果每个元素的长度原大于13，使用Bloom Filter就可以节省内存。


### 错误率估计



## 实现示例

```
#define SIZE 15*1024*1024
char a[SIZE]; /* 15MB*8 = 120M bit空间 */
memset(a,0,SIZE);

int seeds[] = { 5, 7, 11, 13, 31, 37, 61};

int hashcode(int cap,int seed, string key){
	int hash = 0;
	for (int i=0;i<key.length();i++){
		hash = (seed*hash +key.charAt(i));
	}
	return hash & (cap-1);
}

//------------------------------
public class Hash {

    //
    private static int[] hashSeeds = new int[]{33, 53, 79, 97, 113, 137, 163, 181};

    /**
     * 一组哈希
     */
    public static int[] hashes(String key, int slots) {
        int[] hs = new int[8];
        for (int i = 0; i < hs.length; i++) {
            hs[i] = Hash.hash(key, i) % slots;
        }
        return hs;
    }


    /**
     * 单个哈希
     */
    public static int hash(String key, int index) {
        int h = 5381;
        for (int i = 0; i < key.length(); i++) {
            h = hashSeeds[index] * h + key.charAt(i);
        }
        return (h ^ (h >>> 16)) & Integer.MAX_VALUE;
    }

}
```


```
public class ByteBufferBloomFilter  {

    /**
     * 存储BloomFilter数据
     */
    private final ByteBuffer data;

    private final int size;//占用空间


    /**
     * 构造BloomFilter
     * @param size 占用空间（字节数），应设为key总数的1.5倍以上，最大不超过2G
     */
    public ByteBufferBloomFilter(int size) {
        if (size <= 0) {
            throw new IllegalArgumentException("size must > 0");
        }
        this.size = size;
        this.data = ByteBuffer.allocateDirect(size);
    }


    @Override
    public void put(String key) {
        int[] hs = Hash.hashes(key, size);
        for (int i = 0; i < hs.length; i++) {
            int idx = hs[i];
            int b = data.get(idx);
            data.put(idx, (byte) (b | (1 << i)));
        }
    }

    @Override
    public boolean contains(String key) {
        int[] hs = Hash.hashes(key, size);
        for (int i = 0; i < hs.length; i++) {
            int b = data.get(hs[i]);
            if ((b & (1 << i)) == 0) {
                return false;
            }
        }
        return true;
    }


    @Override
    public int size() {
        return size;
    }
}
```

对每个字符串str求哈希就可以使用 `hashcode(SIZE*8,seeds[i],str)` ,i 的取值范围就是 （0，k）。





## 参考  

http://www.cnblogs.com/heaad/archive/2011/01/02/1924195.html  
http://blog.csdn.net/jiaomeng/article/details/1495500    
http://pages.cs.wisc.edu/~cao/papers/summary-cache/node8.html  `哈希函数个数k、位数组大小m` 测试论证
https://blog.csdn.net/tianyaleixiaowu/article/details/74721877
https://juejin.im/post/5bc7446e5188255c791b3360



