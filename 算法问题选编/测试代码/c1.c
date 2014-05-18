// FROM:http://www.gowrikumar.com/c/

#include<stdio.h>

  #define TOTAL_ELEMENTS (sizeof(array) / sizeof(array[0]))
  int array[] = {23,34,12,17,204,99,16};

  int main()
  {
      int d;
      int n = TOTAL_ELEMENTS-2;
      for(d=-1;d <= (TOTAL_ELEMENTS-2);d++)
          printf("%d\n",array[d+1]);

      return 0;
  }


  /*

d 是有符号数，sizeof()计算为无符号数，比较时d会转为无符号数，变成一个大数

  */