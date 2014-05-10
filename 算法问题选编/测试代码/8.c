

#include "stdio.h"

int main(){

	int a = 257;
	unsigned char *result = (unsigned char *)&a;
	printf("%d.%d.%d.%d\n", result[0],result[1],result[2],result[3] );

}