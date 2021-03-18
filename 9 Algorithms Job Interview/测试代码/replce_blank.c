#include "stdio.h"

char *replace_blank(char *source){
	int count = 0;
	char *tail = source;
	if (source == NULL) return NULL;
	while(*tail != '\0'){
		if (*tail == ' ') count++;
		tail++;
	}

	while(count){
		if(*tail != ' '){
			*(tail+2*count) = *tail;	
		}else{
			*(tail+2*count) = '0';
			*(tail+2*count-1) = '2';
			*(tail+2*count-2) = '%';
			count--;
		}
		tail--;
	}

	return source;
}
 
int main(int argc, char const *argv[])
{
	char str[100]="we are happy";
	printf("ret=%s\n",replace_blank(str));
	return 0;
}
