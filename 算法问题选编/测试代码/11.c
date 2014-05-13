

#include "stdio.h"

void print_continuous_sequence_sum(int n){// n=1,2

	int small=1;
	int big=2;
	int sum = small+big;
	while(small<big && big<=n/2+1){

		if (sum==n)
		{
			printf("%d ,%d\n",small,big);

		}

		while(sum>n){
			sum-=small;
			small++;
			if (sum==n)	
			{
				printf("%d, %d\n",small,big);
			}

		}

		big++;	
		sum+=big;

	}



}



int main(int argc, char const *argv[])
{
		

	print_continuous_sequence_sum(115);

	return 0;
}

