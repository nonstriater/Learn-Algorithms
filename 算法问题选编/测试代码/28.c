#include <stdlib.h>
#include <stdio.h>  
  int main()  
  {  
      int* ptr1,*ptr2;  
      ptr1 = malloc(sizeof(int));  
      ptr2 = ptr1;  
      *ptr2 = 10;  
      return 0;  
  }  