// FROM:http://www.gowrikumar.com/c/

#include <stdio.h>
  int main()
  {
      char dummy[80];
      printf("Enter a string:\n");
      scanf("%[^a]",dummy);
      printf("%s\n",dummy);
      return 0;
  }

/**

输入一个串，以字符'a'结尾
*/

