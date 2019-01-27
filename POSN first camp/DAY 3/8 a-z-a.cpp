#include<stdio.h>
main()
{
    int x,i,check=0;
    scanf("%d",&x);
    for(i=0;i<x+1;i++)
    {
        printf("%c",i%26+'A');
        check++;
        if(check+'A' > 'Z')
        {
            printf("\n");
            check = 0;
        }

    }
}

