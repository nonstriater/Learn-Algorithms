
#include <stdio.h>
 #define SIZE 10
  void size(int arr[SIZE])
  {
          printf("size of array is:%d\n",sizeof(arr));
  }

  int main()
  {
          int arr[SIZE];
          size(arr);
          return 0;
  }


  // 32位机器 4， 64位机器 8