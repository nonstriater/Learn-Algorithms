
#include "stdio.h"
#include "time.h"



int fibonacci(int n){

	int result[2] = {0,1};
	if (n<2)
	{
		return result[n];
	}

	return fibonacci(n-1)+fibonacci(n-2);
}


// 循环
int fibonacci2(int n){

	int result[2] = {0,1};

	if ( n<2 )
	{
		return result[n];
	}

	int fibOne=0;
	int fibTwo=1;
	int fibN;
	for (int i = 2; i < n; ++i)
	{
		fibN = fibOne + fibTwo;
		fibOne = fibTwo;
		fibTwo = fibN;
				
	}	

	return fibN;
}



int main(){

	int start,end;
	long result;

	start = clock();
	result=fibonacci2(40);
	end = clock();
	printf("%ld %.6fs",result,(double)(end-start)/CLOCKS_PER_SEC);

	return 0;
}

