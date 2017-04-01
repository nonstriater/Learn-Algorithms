#include "stdio.h"

void _reverse(char *start,char *end){
	if ((start == NULL) || (end == NULL)) return;
	while(start < end){
		char tmp = *start;
		*start = *end;
		*end = tmp;

		start++,
		end--;
	}
}

char *_revert_by_word(char *source){
	char *end = source;
	char *start = source;
	while(*start != '\0'){		
		if (*start == ' '){
			start++;
			end++;
		}else if(*end == ' ' || *end == '\0'){
			_reverse(start,end-1);
			start = end;			
		}else{
			end++;
		}
	}
	return source;
}

char *revert_by_word(char *source){
	char *end = source;
	char *start = source;
	if (source == NULL) return NULL;
	while (*end != '\0') end++;
	end--;

	/*整个句子逆序*/
	_reverse(start,end);

	/*按单词逆序.tneduts  a ma I */
	_revert_by_word(source);

	return source;
}

//为啥运行时 bus error？
int main(int argc, char const *argv[])
{
	char *test = "how are you ?";
	printf("%s\n",_revert_by_word(test));

	//char *test = "I am a  student.";
	//printf("%s\n",revert_by_word(test));
	return 0;
}
