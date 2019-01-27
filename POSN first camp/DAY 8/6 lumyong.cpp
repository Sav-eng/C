#include<stdio.h>
main()
{
    int n,i,j,sum=0,sum1=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%d",j);
        }

        printf("\n");
    }
    for(i=2;i<n-1;i+=1)
    {
        sum+=i;
        sum1+=sum;
    }
    printf("%d",sum1);
}
