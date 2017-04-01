#include <stdio.h>
  int main()
  {
      int cnt = 5, a;

      do {
          a /= cnt;
      } while (cnt --);

      printf ("%d\n", a);
      return 0;
  }

  ///  cnt==1 时，会发生除0错误

  