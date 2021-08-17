  // FROM:http://www.gowrikumar.com/c/

  #include <stdio.h>
  int main()
  {

      char c;
      scanf("%c",&c);
      printf("%c\n",c);

      scanf(" %c",&c);
      printf("%c\n",c);

      return 0;
  }

/*

scanf("%c",&c) 和 scanf(" %c",&c) 区别


使用第二个scanf("%c",&c) 时，系统会将前一个scanf()输入的回车符号读入改变量。
这里为什么加一个“空格”就可以？
scanf带“空格”后，会从输入缓冲区中skip 空白符（空格、tab,换行符），读取一个字符

*/

