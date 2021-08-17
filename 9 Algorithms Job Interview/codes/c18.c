 #include <stdio.h>
  int main()
  {
      int i;
      i = 10;
      printf("i : %d\n",i);
      printf("sizeof(i++) is: %d\n",sizeof(i++));
      printf("i : %d\n",i);
      return 0;
  }

// sizeof()不会对传入的表达式计算 ，所以后面的输入还是i:10
