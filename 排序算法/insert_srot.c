
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


// 归并排序

void merge_sort(int *a, int length){


	

}



// 堆排序

void heap_sort(int *a, int length){



}




#define Max_Number 50000

int main(){

	//int a[] = {4,87,2,32,5,41,2,9};
	// 准备5000个数
	int a[Max_Number];
	for (int i = 0; i < Max_Number; ++i)
	{
		a[i]=rand()%Max_Number;
	}

	clock_t start,finish;

	

	start = clock();

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
	printf("time eclipse: %.4f sec\n", (double)(finish-start)/CLOCKS_PER_SEC); // CLOCKS_PER_SEC 1000 clock()是毫秒

	return 0;
}


