
#include <stdio.h>

int main()
{
        float f=0.0f;
        int i;

        for(i=0;i<10;i++)
                f = f + 0.1f;

        if(f == 1.0f)
                printf("f is 1.0 \n");
        else
                printf("f is NOT 1.0\n");

        return 0;
}

//  浮点数判相等 
