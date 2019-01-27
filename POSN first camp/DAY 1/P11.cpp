#include<stdio.h>
main()
{
    int i,j,sum;
    for(i=1;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            sum = i+j;
            if(sum>5)sum-=5;
            printf("%d",sum);
        }
        printf("\n");
    }
}
