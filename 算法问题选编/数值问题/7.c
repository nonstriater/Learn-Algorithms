
#include "stdio.h"

int main(){

	int j,k,m;
	int i= (j=4,k=5,m=8);
	printf("%d\n", i);

	i= (j==4)?:0;
	printf("i=%d\n", i);

	return 0;
}
