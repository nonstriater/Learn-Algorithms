  #include <stdio.h>
  #include <stdlib.h>

  #define SIZEOF(arr) (sizeof(arr)/sizeof(arr[0]))

  #define PrintInt(expr) printf("%s:%d\n",#expr,(expr))
  int main()
  {
      /* The powers of 10 */
      int pot[] = {
          0001,
          0010,
          0100,
          1000
      };
      int i;

      for(i=0;i<SIZEOF(pot);i++)
          PrintInt(pot[i]);
      return 0;
    }

    // 以0大头的都是8进制数据