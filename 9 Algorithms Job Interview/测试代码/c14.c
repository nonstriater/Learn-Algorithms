#include<stdio.h>
  int main()
  {
      int a=1;
      switch(a)
      {   int b=20;
          case 1: printf("b is %d\n",b);
                  break;
          default:printf("b is %d\n",b);
                  break;
      }
      return 0;
  }


  // In my computer ,output:b is 32767  switch中只会从case开始执行，b会随机输出