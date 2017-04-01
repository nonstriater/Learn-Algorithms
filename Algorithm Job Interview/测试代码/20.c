#include <stdlib.h>
#include <stdio.h>
  #define PrintInt(expr) printf("%s : %d\n",#expr,(expr))
  int main()
  {
      int y = 100;
      int *p;
      p = malloc(sizeof(int));
      *p = 10;
      y = y / *p; 
      PrintInt(y);
      return 0;
  }