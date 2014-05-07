
#include "stdio.h"


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

void fast_sort(int *a, int length){




}


// 堆排序

void heap_sort(int *a, int length){


	
}






int main(){

	int a[] = {4,87,2,32,5,41,2,9};
	//insert_sort(a,sizeof(a)/sizeof(int));
	//select_sort(a,sizeof(a)/sizeof(int));
	bubble_sort(a,sizeof(a)/sizeof(int));

	printf("after sort:\n");
	for (int i = 0; i < sizeof(a)/sizeof(int); ++i)
	{
		printf("  %d  ",a[i]);
	}
	return 0;
}


