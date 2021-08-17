#include "stdio.h"

char *delete_occurence_character(char *src , char target){
	char *front = src;
	char *rear = src;
	while(*front != '\0'){
		if (*front != target){
			*rear = *front;
			rear++;
		}
		front++;
	}
	*rear = '\0';
	return src;
}

int main(int argc, char const *argv[])
{
	char test[] = "abcdeccba";
	printf("%s\n", delete_occurence_character(test,'c'));
	return 0;
}
