# 查找算法

* 顺序查找
* 二分查找
* 分块查找
* 动态查找
* 哈希表


## 顺序查找

顺序表查找。复杂度O(n)

## 二分查找

有序表中查找我们可以使用二分查找。

```
/*
eg: [1,3,5,6,7,9] k=6
@return 返回元素的索引下表，找不到就返回-1
*/
int binary_search(int *a,int length,int k){
	int low = 0;
	int high = length-1;
	int mid;

	while(low<high){//bug
		mid = (low+high)/2;
		if (a[mid] < k) low = mid+1; //不+1的话， 会有个bug： 可能 死循环
		if (a[mid == k]) return mid;
		if (a[mid] > k) high = mid-1; 
	}

	return -1;
}
```


```
注意细节
mid+1/mid-1 , 否则的话，有可能死循环

while(low <= high) 而不是  while(low<high)

mid = (low+high)/2;  跟  mid = left + (right - left) / 2; 有什么区别？
```

如果搜索有序数列是 `[1,2,2,2,2,3]` 这种，想得到 target 的左侧边界，即索引 1，或者我想得到 target 的右侧边界，即索引 4 ； 这时候怎么处理呢？

你也许会说，找到一个 target，然后向左或向右线性搜索不行吗？可以，但是不好，因为这样难以保证二分查找对数级的复杂度了。



寻找左侧边界的二分搜索

```
int left_binary_search(int[] nums, int target) {
    if (nums.length == 0) return -1;
    int left = 0;
    int right = nums.length; // 注意

    while (left < right) { // 注意
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) { //找到 target 时不要立即返回，而是缩小「搜索区间」的上界 right
            right = mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid; // 注意 , 这里没有 -1
        }
    }
    return left;
}
```




## 分块查找

块内无序，块之间有序；可以先二分查找定位到块，然后再到块中顺序查找。


## 动态查找

这里之所以叫 动态查找表，是因为表结构是查找的过程中动态生成的。查找结构通常是二叉排序树，AVL树，B- ，B+等。这部分的内容可以去看『二叉树』章节


## 哈希表

哈希表以复杂度O(1)的成绩位列所有查找算法之首，大量查找的数据结构中都可以看到哈希表的应用。











