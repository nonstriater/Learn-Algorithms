  #include<stdio.h>
  int main()
  {
          int a=10;
          switch(a)
          {
                  case '1':
                      printf("ONE\n");
                      break;
                  case '2':
                      printf("TWO\n");
                      break;
                  a:
                      printf("NONE\n");
          }
          return 0;
  }


  //什么也不输出, “default”这里随便什么都没有编译错误