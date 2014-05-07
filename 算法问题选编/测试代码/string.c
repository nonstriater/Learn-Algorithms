
#include "stdio.h"

typedef int BOOL;
#define YES 1
#define NO 0


// 反序
void revert(const char *source,char *dest){

	const char *s = source;
	char *end = dest;
	while(*s){
		*end++ = *s++; //先拷贝字符串
	}
	*end='\0';
	end--;// 指向最后一个字符

	while(end>dest){

		char tmp = *end;
		*end = *dest;
		*dest = tmp;

		end--;
		dest++;
	}	


}

// 回文，或 对称
BOOL symmetrical(const char *scr,int length){

	const char *end = scr+length-1;
	BOOL is=YES;

	while(end>scr){

		if (*scr++ != *end--)
		{
			is=NO;
		}

	}

 	return is;
}


//找出第一个只出现一次的字符,找不到就返回‘0’
char first_appear_only_once(const char *source){

	// 建立hash表
	const int length=256;
	int hash_table[length];
	for (int i = 0; i < length; ++i)
	{
		hash_table[i]=0;
	}

	//第一次扫描，建立hash表
	const char *tmp = source;
	while(*tmp){
		hash_table[*tmp++]++;
	}

	// 第二次扫描
	while(*source){

		if(hash_table[*source]==1){

			return *source;
		}

		source++;
	}

	// 没找到
	if (!*source)
	{
		return '0';
	}

	return '0';
}




// 最大对称子串的长度
int max_symmetrical_char_length(const char *scr){

	


	return 0;
}


// 找最大数字子串
int continumax(char *outputstr,char *intputstr){


	return 0;
}

// 最大连续递增数字串

int continuousnum(const char *input, char *output){


	return 0;

}



// 2个字符串的最长公共子串
int longest_common_subsequence(const char *s1,const char *s2, char *common){


	return 0;

}



// 找子串
char *strstr(const char *haystack, const char * needle){

	return NULL;

}

// 子串个数
char *sub_str_count(const char *src, const char *substr, int *count){


	return NULL;

}




// 删除子串
char *delete(char *source,const char *del,BOOL greedy){


	return NULL;
}




// 字符串拷贝
char *strcpy(char *strDest, const char *strSrc){


	return NULL;
}




BOOL isBrother(const char *first,const char *secd){


	return YES;
}

// 字符串压缩
char *compress(const char *src,char *dest){


	return NULL;

}

// 删除其中的数字并压缩

char *filternumber(const char*src,char *dest){


	return NULL;
}

// 删除指定字符
char *delete_character(char *src , char target){

	return NULL;

}





// 统计文件中单词的出现的个数
void statistics(FILE *fd){


}



// 字符串中字符的所有排列






int main(int argc, char const *argv[])
{

	// 反转
	char *reverse = "nonstriater";
	char reversed[20];
	revert(reverse,reversed);
	printf("%s after reverse : %s\n", reverse,reversed);


	// 回文
	char symmetri[] = "dacbcacbcad";
	printf("%s : %d\n", symmetri, symmetrical(symmetri,sizeof(symmetri)-1) );

	char unsymmetrical[] = "aaacbdaa";
	printf("%s : %d\n", unsymmetrical, symmetrical(unsymmetrical,sizeof(unsymmetrical)-1) );


	// 第一次出现一次的字符
	printf("%s第一次出现一次的字符是：%c\n",symmetri,first_appear_only_once(symmetri) );// '0'
	printf("%s第一次出现一次的字符是：%c\n",unsymmetrical,first_appear_only_once(unsymmetrical) ); // 'c'

	return 0;
}












