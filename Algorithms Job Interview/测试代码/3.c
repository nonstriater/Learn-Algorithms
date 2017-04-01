
#include "stdio.h"
#include "stdlib.h"

char *integer_to_bin(long integer){

	int bit_num = sizeof(long)*8;
	char *buffer= (char *)malloc(bit_num+1);
	if (buffer==NULL)
	{
		return "malloc error";
	}
	buffer[bit_num]='\0';

	for (int i = 0; i < bit_num; ++i)
	{
		buffer[i]= integer<<i>>(bit_num-1);
		buffer[i]= buffer[i]==0?'0':'1';

	}
	return buffer;

}

char *integer_to_hex(long integer){

	int bit_num=sizeof(long)*8/4;
	char *buffer=(char *)malloc(bit_num+3);
	buffer[0]='0';
	buffer[1]='x';
	buffer[bit_num+2]='\0';
	char *tmp=&buffer[2];

	for (int i = 0; i < bit_num; i++)
	{
		tmp[i]= integer<<(i*4)>>(bit_num*4-4);
		tmp[i]= tmp[i]>=0?tmp[i]:tmp[i]+16;
		tmp[i]= tmp[i]<10?(tmp[i]+48):(tmp[i]-10+'A');
	}

	return buffer;
}


/*

A  65
0  48

*/



int main(){


	printf("b(11) = %s\n", integer_to_bin(11));
	printf("b(1023) = %s\n",integer_to_bin(1023) );
	printf("b(23564) = %s\n",integer_to_bin(23564) );


	printf("h(11) = %s\n", integer_to_hex(11));
	printf("h(1023) = %s\n",integer_to_hex(1023) );
	printf("h(23564) = %s\n",integer_to_hex(23564) );
	printf("b(11) = %x\n", 11);
	printf("b(1023) = %x\n",1023 );
	printf("b(23564) = %x\n",23564 );


	return 0;
}