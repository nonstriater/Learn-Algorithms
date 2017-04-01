
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

// 按单词逆向 如 this is a sentence 输出 sentence a is this
// 先按单词逆序，再对整个句子逆序
void revertByWord(const char *src, char *dest){

	// 先拷贝字符串到dest
	char *tmp = dest;
	char *dest_end;
	while(*src){
		*tmp++ = *src++;
	}
	*tmp='\0';
	dest_end = tmp-1; //这里留作下面用；
	tmp = dest;

	// 扫描一遍 dest，按单词逆序
	char *start=dest-1,*end=dest;
	while(*tmp){

		if (*tmp == ' ')//逆序
		{
			start++;

			//对单词逆向
			while(end>start){
				*start = *start + *end;
				*end   = *start - *end;
				*start = *start - *end;

				start++;
				end--;
			}

			start=tmp;// 如果句子中又多个连续空格，也会对空格做逆序，浪费cpu

		}
		tmp++;
		end=tmp-1;
	}

	if (!*tmp)//最后一个字符,对最后一个单词逆序
		{
			start ++;
			while(end>start){
				*start = *start + *end;
				*end   = *start - *end;
				*start = *start - *end;

				start++;
				end--;	
			}
		}


	tmp = dest;
	
	// 逆向整个句子
	while(dest_end>tmp){

		*tmp 		= *tmp + *dest_end;
		*dest_end 	= *tmp - *dest_end;
		*tmp 		= *tmp - *dest_end;

		tmp++;
		dest_end--;
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

	int max_symmetrical_length=1;



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
char *strcpy(const char *src,char *dest){

	char *tmp = dest;
	while(*src){

		*dest++ = *src++;

	}
	*dest = '\0';
	
	return tmp; 
}



// aabcd & bcad  ,  abc&bca
BOOL isBrother(const char *first,const char *secd){


	return YES;
}




// 字符串就地压缩 如 “aaabcc” “a3bc2”
/*
	注意连续字符大于9的情况
*/
void compress(char *src){

	if (*src == NULL)
	{
		return;
	}

	int count = 1;
	char *back=src,forward=src+1;

	while(*forward){

		count = 1;
		if (*forward == *back)
		{
			count++;
			forward++;	

		}else{ //

			if (count!=1)
			{
				back++;
				*back=count;

			}

		}


	}

	*++back = '\0';

}




// 删除其中的数字并压缩,2个指针，一前一后
void filternum(char *src){

	if (!*src)
	{
		return;
	}

	char *back=src ,*forward=src;
	while(*forward){
		if (*forward >= '0' && *forward <= '9')
		{
				forward++;
		}else{
			*back++ = *forward++;
		}

	}
	*back='\0';


	// 局部变量释放，不能作为返回值
}

// 删除字符串中的数字，不改变原串,同上
char *filternumber(const char*src,char *dest){


	return NULL;
}

// 删除指定字符，不开辟空间
void delete_character(char *src , char target){

	char *back=src,*forward = src;

	while(*forward){

		if (*forward == target)
		{
			forward++;

		}else{

			*back++ = *forward++;


		}

	}

	*back = '\0';

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


	// 按单词逆序
	char *sentence = "this is a sentence!"; // "this is    a   sentence"
	char dest[50];
	revertByWord(sentence,dest);
	printf("%s revert by word: %s\n",sentence,dest );



	// 回文
	char symmetri[] = "dacbcacbcad";
	printf("%s : %d\n", symmetri, symmetrical(symmetri,sizeof(symmetri)-1) );

	char unsymmetrical[] = "aaacbdaa";
	printf("%s : %d\n", unsymmetrical, symmetrical(unsymmetrical,sizeof(unsymmetrical)-1) );


	// 第一次出现一次的字符
	printf("%s第一次出现一次的字符是：%c\n",symmetri,first_appear_only_once(symmetri) );// '0'
	printf("%s第一次出现一次的字符是：%c\n",unsymmetrical,first_appear_only_once(unsymmetrical) ); // 'c'

	// 过滤数字
	char *charnumber = "this is 58tongcheng12haha!";
	//filternum(charnumber);
	printf(" after filter: %s\n", charnumber );


	// 过滤指定字符
	//delete_character(charnumber,'i'); // 居然会出 bus error！！！！！？？？？
	printf("after filter:%s\n", charnumber);





	return 0;
}












