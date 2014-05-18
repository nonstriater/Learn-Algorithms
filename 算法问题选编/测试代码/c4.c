  #include <stdio.h>
  #include <unistd.h>
  int main()
  {
          while(1)
          {
                  fprintf(stdout,"hello-out");
                  fprintf(stderr,"hello-err");
                  sleep(1);
          }
          return 0;
  }


  /*

stdout 会缓冲输出

\n
fflush()

setbuf(stdout,NULL)

  */