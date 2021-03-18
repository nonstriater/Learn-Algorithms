

#include "stdio.h"

void generate(int a,int b,int N ,int * Q){

	int p=1,q=1;
	int tmpA,tmpB;

	for (int i = 0; i < N; ++i)
	{
		tmpA = a*p;
		tmpB = b*q;

		if (tmpA>tmpB)
		{
			Q[i]=tmpB;
			q++;
				
		}
		else if(tmpA<tmpB)
		{
			Q[i]=tmpA;
			p++;

		}
		else{// ==
			Q[i]=tmpA;
			p++;
			q++;
		}
	}
}


int main(int argc, char const *argv[])
{
	
	int a[10];
	generate(3,5,10,a);
	for (int i = 0; i < 10; ++i)
	{
		printf(" %d \n", a[i]);
	}

	return 0;
}
