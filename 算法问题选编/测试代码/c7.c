#include <stdlib.h>
int main()
  {
      int* p;
      p = (int*)malloc(sizeof(int));
      *p = 10;
      return 0;
  }