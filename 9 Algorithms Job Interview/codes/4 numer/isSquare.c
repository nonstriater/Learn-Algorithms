
#include "stdio.h"

int isSquare(unsigned integer){

	if (integer==1 || integer==0)
	{
		return integer;
	}

	int divider=2,result=integer/divider;

	while(result>divider){

		divider++;
		result = integer/divider;

	}

	if (result!=divider)
	{
		return -1;
	}

	return result;
}


int main(int argc, char const *argv[])
{
	// 243,1849（43），289(17), 64(8)
	
	int a[] = {1849,144,243,289,64,1194877489};
	for (int i = 0; i < sizeof(a)/sizeof(int); ++i)
	{
		int ret =  isSquare(a[i]);

		if (ret==-1)
		{
			printf("%d 不是某个数的平方\n",a[i]);
		}else{

			printf("%d 是 %d 的平方\n", a[i], ret);
		}

	}

	return 0;
}




