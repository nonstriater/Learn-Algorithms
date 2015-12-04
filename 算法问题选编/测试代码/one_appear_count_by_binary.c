#include "stdio.h"

int one_appear_count_by_binary(int num){
	int count = 0;
	while(num !=0 ){
		num &=  num-1;
		count++;
	}
	return count;
}

int main(int argc, char const *argv[])
{
	int test = 10;
	printf("%d\n", one_appear_count_by_binary(test));
	printf("%d\n", one_appear_count_by_binary(32+1));
	return 0;
}