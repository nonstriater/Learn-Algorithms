
#include "stdio.h"


void reorder(int *data, int length){

	int i=0;
	int j=length-1;

	while(i<j){

		if (!isEvenNum(data[i]) )
		{
			i++;
			continue;
		}

		if (isEvenNum(data[j]) )
		{
			j--;
			continue;	
		}
		
		//交换
		int tmp ;
		tmp 	= data[i];
		data[i] = data[j];
		data[j] = tmp;

	}

}

int isEvenNum(int n){

	return (n&1) == 0;
}


int main(int argc, char const *argv[])
{
	
	int a[]= {5,2,7,8,9,34,21,6};

	reorder(a,8);

	for (int i = 0; i < 8; ++i)
	{
		printf(" %d ", a[i]);
	}



	return 0;
}
