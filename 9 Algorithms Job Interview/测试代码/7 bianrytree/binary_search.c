

#include "stdio.h"

int binary_search_first(int *a,int length,int key){

	int low=0;
	int high = length-1;
	int mid = 0;

	while(low<high){

		mid = (low+high)/2;
		if (a[mid]>=key)//往左找
		{
			high = mid;
		}else{

			low = mid+1;
		}

	}
	return high;

}

int binary_search_last(int *a,int length,int key){

	int low = 0;
	int high = length -1;
	int mid = 0;

	while(low<high){

		mid = (low+high+1)/2;
		if (a[mid]<=key)// 往右找	
		{
			low=mid;
		}else{
			high = mid-1;
		}

	}

	return low;
}


int element_appear_times(int *a,int length,int key){

	printf("(%d) first appear at index %d\n",key,binary_search_first(a,length,key));
	printf("(%d) last appear at index %d\n",key,binary_search_last(a,length,key));
	return binary_search_last(a,length,key)-binary_search_first(a,length,key)+1;

}


int main(){


	int a[] = {2,3,4,4,4,4,4,5,5,7,7,11,11,11,11,11,32,32,54};

	printf("(2)appear times = %d\n", element_appear_times(a,sizeof(a)/sizeof(int),2) );
	printf("(4)appear times = %d\n", element_appear_times(a,sizeof(a)/sizeof(int),4) );
	printf("(11)appear times = %d\n", element_appear_times(a,sizeof(a)/sizeof(int),11) );
	printf("(36)appear times = %d\n", element_appear_times(a,sizeof(a)/sizeof(int),36) );
	printf("(54)appear times = %d\n", element_appear_times(a,sizeof(a)/sizeof(int),54) );
	return 0;
}

