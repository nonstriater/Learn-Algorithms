#include "stdio.h"

int longest_continuious_number(const char *input,char *output){
	int max = 0;
	char *start= input;
	char *mid = input;
	char *end = input;
	int tmp = 0;
	if (input == NULL || output == NULL) return 0;

	while (*end != '\0'){
		if (*end < '0' || *end > '9'){//字母
			if(tmp > max){
				max = tmp;
				start = mid;
			}
			tmp = 0;
		}else{//数字
			if (tmp == 0){//发现数字	
				mid = end;
			}
			tmp++;
		}
		end++;
	}

	//修改已数字结尾的bug
	if(tmp > max){
		max = tmp;
		start = mid;
	}

	//copy
	int i=0;
	while(i<max){
		*(output+i) = *(start+i);
		i++;
	}
	*(output+i)='\0';

	return max;
}

int main(int argc, char const *argv[])
{
	const char test[] = "abcd12345ed125ss123456789";
	char output[100] = {};
	int max = longest_continuious_number(test,output);
	printf("max=%d,number=%s\n", max,output);

	return 0;
}




