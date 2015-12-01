#include "stdio.h"

char *proc(char *str){
	char *start = str;
	char *end = str;
	if (str == NULL) return NULL;
	while(*end != '\0') end++;
	end--;

	while(start < end){
		if (*start >= 'A' && *start <= 'Z'){//大写
			if (*end >= 'a' && *end <= 'z'){
				char tmp = *start;
				*start = *end;
				*end = tmp;

				start++;
			}
			end--;
		}else{//小写
			if (*end >= 'A' && *end <= 'Z'){
				end--;
			}
			start++;
		}
	}	
	return str;
}

int main(int argc, char const *argv[])
{
	char test[] = "HaJKPnobAACPc";//"char *test" always make "28767 bus error"
	printf("%s\n", proc(test));
	return 0;
}
