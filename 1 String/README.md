# 字符串

字符串在计算机中的应用非常广泛，这里讨论有关字符串的最重要的算法：

* 排序
* 查找
	* 单词查找树
	* 子串查找
* 正则表达式:正则表达式是模式匹配的基础,是一个一般化了的子字符串的查找问题,也是搜索工具grep的核心。
	* 模式匹配
	* grep
* 数据压缩
	* 赫夫曼树
	* 游程编码


[Java中 String实现 参考这里](java%20String.md)

## 查找

* KMP
* BM


## 滑动窗口


使用滑动窗口解决字符串子串问题，代码框架
```
int left = 0, right = 0;

while (right < s.size()) {
    // 增大窗口
    window.add(s[right]);
    right++;

    while (window needs shrink) {
        // 缩小窗口
        window.remove(s[left]);
        left++;
    }
}
```



## 参考

《Algorithms》





