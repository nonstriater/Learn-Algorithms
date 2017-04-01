
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

// 插入排序
void insert_sort(int *a,int length){

	int tmp ;
	int i,j;
	for (i = 1; i < length; ++i)
	{
			
		for ( tmp=a[i],j=i-1 ; j>=0 && a[j] > tmp ; j--)
		{
			a[j+1]=a[j];
		}
		// j+1是插入的位置
		a[j+1]=tmp;

	}

}


// 选择排序

void select_sort(int *a,int length){

	int min_index,tmp;
	int j;

	for (int i = 0; i < length; ++i)
	{
		for (j = i+1 ,min_index=i; j < length; ++j)// 不能写成for (int j = i+1 ,min_index=i; j < length; ++j)
		{
			if (a[min_index]>a[j])
				{
					min_index=j;
				}	
		}		

		//min_index是最小的元素的index
		if (min_index!=i)
		{
			tmp=a[i];
			a[i]=a[min_index];
			a[min_index]=tmp;
			
		}
		
	}

}


// 冒泡排序

void bubble_sort(int *a, int length){

	int tmp ;

	for (int i = 0; i < length-1; ++i) // 第i轮排序
	{
		for (int j = 0; j < length-i; ++j) 
		{
			if (a[j] > a[j+1])
			{
				tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
		}

	}

}


// 快速排序

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

void quicksort(int *a, int left, int right){

	if (left<right)//加上这个，不然有死循环，造成堆栈溢出
	{
		int i = partion(a,left,right);
		quicksort(a,left,i-1); 
		quicksort(a,i+1,right);
	}
}


// 堆排序

void heap_swop(int *a,int *b){

	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}



//自顶向下调整
void heap_public_adjust(int *a,int i,int length){

	// 三个数里取最大的一个  a[i],a[2i+1],a[2i+2],跟a[i]交换；然后是 a[(i-1)/2],a[i],a[i+1] .. 一直到a[0]
		int tmp = i , max;//
		while(2*tmp+1<length){
			max = 2*tmp+1;
			//三个数里取最大的一个  a[tmp],a[2tmp+1],a[2tmp+2] 
			if (2*tmp+2<length)// 越界检查
			{
				if (a[max] < a[2*tmp+2])// 先选出最大的子节点
				{
					max = 2*tmp+2;
				}
			}

			// 和最大孩子比
			if (a[tmp] >= a[max])
			{
				break;
			}
			else
			{
				heap_swop(&a[tmp],&a[max]);	
				tmp = 2*tmp+1;
			}

		}

}


// 从第一个非叶子节点a[(length-2)/2]，开始做调整, 跟自己的子节点比较，把最大的孩子换上来就是创建最大堆，
//反之，把最小的孩子换上来就是创建最小堆 一直到a[0]
void heap_build(int *a,int length){

	
	for (int i = (length-2)/2; i >=0 ; --i)
	{
		// 三个数里取最大的一个  a[i],a[2i+1],a[2i+2],跟a[i]交换；然后是 a[(i-1)/2],a[i],a[i+1] .. 一直到a[0]
		heap_public_adjust(a,i,length);
	
	}	

}

// 自顶向下调整
void heap_adjust(int *a,int length){

	heap_public_adjust(a,0,length); //对0号调整
}


void heap_sort(int *a, int length){

	// 建立堆 大根堆，递增排序
	heap_build(a,length);

	for (int i = length-1; i >0; --i)
	{
		//交换
		heap_swop(&a[0],&a[i]);
		//调整
		heap_adjust(a,i);
	}

}



// 归并排序

// 合并2个有序数组,分配一个临时空间，装a，b的结果，最后，将合并结果拷贝到数组A，是否临时空间
void merge_array(int *a,int size_a,int *b, int size_b){


	int *tmp = malloc( (size_a+size_b)*sizeof(int) );
	int i,j,k;
	i=j=k=0;

	while(i<size_a && j<size_b){

		tmp[k++] = (a[i]>b[j])?b[j++]:a[i++];
	}

	while(i<size_a){

		tmp[k++]=a[i++];
	}

	while(j<size_b){

		tmp[k++]=b[j++];
	}

	for (int p = 0; p < k; ++p)
	{
		a[p] = tmp[p];
	}

	free(tmp);

}


void merge_sort(int *a, int length){


	if (length>1)
	{
		
		merge_sort(a,length/2);
		merge_sort(a+length/2,length-length/2);

		merge_array(a,length/2,a+length/2,length-length/2);
	}



}


///////////////////////////////////////////////


#define Max_Number 5000

int main(){

	//int a[] = {4,87,2,32,5,2,9,49,49,23,45,2,41};
	//准备5000个数
	int a[Max_Number];
	for (int i = 0; i < Max_Number; ++i)
	{
		a[i]=rand()%Max_Number;
	}

	clock_t start,finish;

	

	start = clock();
	merge_sort(a,sizeof(a)/sizeof(int));    // 0.002s,可以看到，归并排序还是很快的
	//heap_sort(a,sizeof(a)/sizeof(int));  // 有buggggggg
	//quicksort(a,0,sizeof(a)/sizeof(int)-1); // 0.01s
	//insert_sort(a,sizeof(a)/sizeof(int));  //  3.85s
	//select_sort(a,sizeof(a)/sizeof(int));   // 5.3s
	//bubble_sort(a,sizeof(a)/sizeof(int));    // 12.5s
	finish = clock();

	printf("after sort:\n");
	for (int i = 0; i < sizeof(a)/sizeof(int); ++i)
	{
		printf("  %d  ",a[i]);
	}
	printf("time eclipse: %.6f sec\n", (double)(finish-start)/CLOCKS_PER_SEC); // CLOCKS_PER_SEC 1000 clock()是毫秒

	return 0;
}


