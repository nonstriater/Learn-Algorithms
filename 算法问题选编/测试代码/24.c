  #include <stdio.h>
  int main()
  {
      int i = 6;
      if( ((++i < 7) && ( i++/6)) || (++i <= 9))
          ;
      printf("%d\n",i);
      return 0;
  }

  // && 优先级大于 || 