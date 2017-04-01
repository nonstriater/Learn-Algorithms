
#include "stdio.h"
#include "string.h"

int string_to_integer(char *s,int length){

	if (length>1)
	{
		return s[0]=='-'?string_to_integer(s,length-1)*10-(s[length-1]-'0'):string_to_integer(s,length-1)*10+s[length-1]-'0';
	}else{
		return s[0]=='-'?-1/10:s[0]-'0';

	}
}
	
/* 问题：
1. s是空字符串
2. s传参为非数字字符
3. 超出整数所能表示范围
*/


int main(){

	char *s = "4323";

	printf("integer == %d\n",string_to_integer(s,strlen(s)) );
	printf("integer == %d\n",string_to_integer("12342",5));
	printf("integer == %d\n",string_to_integer("-11",3) );
	printf("integer == %d\n",string_to_integer("-5",2) );
	printf("integer == %d\n", string_to_integer("3",1));

	printf("integer == %d\n", string_to_integer("abcd",4));
	printf("integer == %d\n", string_to_integer("a",1));

	return 0;
}
