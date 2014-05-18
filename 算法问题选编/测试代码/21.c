#include <stdio.h>
  int main()
  {
      int day,month,year;
      printf("Enter the date (dd-mm-yyyy) format including -'s:");
      scanf("%d-%d-%d",&day,&month,&year);
      printf("The date you have entered is %d-%d-%d\n",day,month,year);
      return 0;
  }