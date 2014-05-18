 #include "c13-1.c"

 extern int *arr;
  int main()
  {
      arr[1] = 100;
      return 0;
  }


/**
类型并不匹配，所以导致这里的arr并没有指向c13-1.c中声明的arr[80],应该修改为 extern int arr[]

int *arr 和 int arr[80] 区别？




*/
