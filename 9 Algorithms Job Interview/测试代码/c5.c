
// FROM:http://www.gowrikumar.com/c/
  #include <stdio.h>
  #define f(a,b) a##b
  #define g(a)   #a
  #define h(a) g(a)

  int main()
  {
          printf("%s\n",h(f(1,2))); // 
          printf("%s\n",g(f(1,2))); // f(1,2)
          return 0;
  }


