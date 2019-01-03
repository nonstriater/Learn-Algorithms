注意：
Pivot的选择是一门学问，直接影响到快速排序算法的效率。
如果只是简单地选择第一个元素或者最后一个元素，那如果遇到逆序数列，或者已经预处理的数列，则可能降低算法的效率
比如逆序数列，可能时间复杂度达到pow(n,2)
选择数列中值，从实际经验上看来，是一个很好的解决方案
中值 = min(max(arr[begin] + arr[end]) + arr[(end-begin)/2])

void quicksort(int *a, int left, int right){
        if (left<right)//加上这个，不然有死循环，造成堆栈溢出，这也是递归结束条件
        {
            int i = partion(a,left,right);//使得局部有序，i作为分隔
            quicksort(a,left,i-1); 
            quicksort(a,i+1,right);
        }
    }

// 挖坑填数，2边向中间扫描
int partion(int *a, int start,int end){
int i=start,j=end;
int tmp = a[i]; // 这里要做越界检查
while(i<j){
    // 从后向前扫描，找到第一个小于tmp的值，来填a[i]
     while(i<j && a[j]>=tmp){
         j--;
    }   
     if (i<j)//找到了,这时候a[j]为坑 
    {   
        a[i++] = a[j];  
    }
    // 从左向右扫描，找一个大于 tmp的 数， 去填坑a[j]
    while(i<j && a[i]<tmp){
        i++;
    }
    if (i<j)
    {
        a[j++]=a[i];
    }
}
//扫描完成后，i==j
a[i]=tmp;
return i;
}

