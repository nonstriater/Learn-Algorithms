#include "stdio.h"

char char_first_appear_once(const unsigned char *source){
	int hash[256]={0};
	char *tmp = source;
	if (tmp == NULL) return '\0';
	while(*tmp != '\0'){
		hash[*tmp]++;
		tmp++;
	}

	tmp = source;
	while(*tmp != '\0'){
		if (hash[*tmp] == 1) return *tmp;
		tmp++;
	}
	return '\0';
}


int main(int argc, char const *argv[])
{
	char *test = "77ah-ba-ccdeff";
	char c = char_first_appear_once(test);
	printf("c=%c\n", c);/* c = 'h'*/
	return 0;
}

