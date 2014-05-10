
#include "stdio.h"  // fwrite
#include "unistd.h" // write
#include "stdlib.h" // itoa
#include "string.h"

#define test_file_path2 "./ip2.txt"
#define test_file_path "./ip.txt"
#define ip_count 100000000 //随机1亿个IP
#define tmp_file_count 32

#define mem_count 128*1024*1028 //128MB个IP空间


int hash(unsigned i){

	return i>>27;

}


int main(){


	// 模拟创建一个文件，产生测试用的IP
	// FILE *fd;
	// fd  = fopen(tmp_file_path,"a+");
	// for (int i = 0; i < ip_count;++i)
	// {
	// 	//char c[] = "this is sentence!";
	// 	unsigned random_ip = (unsigned)rand();
	// 	char tmp[50];
	// 	sprintf(tmp,"%d",random_ip);
	// 	//printf("random ip = %s\n",tmp);
	// 	fwrite(tmp,strlen(tmp),1,fd);
	// 	fputc('\n',fd);//加入换行符号
	// }


	//创建临时文件
	FILE *fd[tmp_file_count];
	for (int i = 0; i < tmp_file_count; ++i)
	{		
		char file_path[128];
		//s[0]=(char)(i+48);
		//char *file_path =  strcat("./ipslice/ipslice",s) ; // 这样写出现 bus error！！！
		sprintf(file_path,"./ipslice/ipslice%d",i);
		fd[i] = fopen(file_path ,"a+" );
		if ( !fd[i])
		{
			printf("file %d open fail!! \n" ,i);
		}
	}




	//开始读测试数据IP，按IP，映射到32个文件中
	FILE *testfd = fopen(test_file_path2,"r");
	if (!testfd)
	{
		printf("file open fail !!\n");
		exit(-1);
	}
	unsigned tmp_data;
	while( getline() ){ //能读到数据      // fread(&tmp_data,sizeof(unsigned),1,testfd) , C语言中没有getline() 这样的函数
		
		printf("%d\n",(unsigned)tmp_data );
		int key = hash((unsigned)tmp_data);// key值即为对应文件fd

		int size = fwrite(&tmp_data,sizeof(unsigned),1,fd[key]);
		printf("写入数据size=%d ,key=%d\n",size, key );

		//跳过换行符
		fseek(testfd,1,SEEK_CUR);
	}




	// 依次读入每个文件并统计， hash_map 统计每个区间段的最大IP
	int hash_map[mem_count]; 
	int max_ip;
	int max_times;

	for (int i = 0; i < tmp_file_count; ++i)
	{
		
		// hash统计
		while(){}

		//hash 表里找出最大的，变量一遍	
		for (int i = 0; i < mem_count; ++i)
		{
			/* code */
		}

	}

	

	// 释放
	for (int i = 0; i < tmp_file_count; ++i)
	{
		fclose(fd[i]);
	}


	return 0;
}



/**
关于warning
implicit declaration of function 'itoa' is invalid in C99

itoa() 函数并不是一个 standard functions ANSI C standard


inet_ntop() // 整数转换成 .分 ip地址 字符串
inet_nton() // 

inet_aton() //

struct in_addr

*/







