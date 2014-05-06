
#include "stdio.h"


int factorial(int n){

	int ret=0;
	(n==0) || (ret=n+factorial(n-1));
	return ret;
}


int main(){

	int n=10;
	printf("factorial(10)= %d\n",factorial(10));
	printf("factorial(5)= %d\n",factorial(5));
	printf("factorial(1)= %d\n",factorial(1));
	printf("factorial(0)= %d\n",factorial(0));

	return 0;
}

