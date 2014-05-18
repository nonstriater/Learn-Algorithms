// FROM:http://www.gowrikumar.com/c/

#include <stdlib.h>
  #include <stdio.h>
  void Error(char* s)
  {
      printf(s);
      return;
  }

  int main()
  {
      int *p;
      p = malloc(sizeof(int));
      if(p == NULL)
      {
          Error("Could not allocate the memory\n");
          Error("Quitting....\n");
          exit(1);
      }
      else
      {
          /*some stuff to use p*/
        Error("Could not allocate the memory\n");
          Error("Quitting....\n");
          Error(5);
      }
      return 0;
  }

  /*

潜在的问题是：

Error函数中，如果输入的参数不是字符串，比如传一个整数5，5被转成一个内存地址，printf这时候访问就会出问题了。
$1 = 0x5 <error: Cannot access memory at address 0x5>

  */