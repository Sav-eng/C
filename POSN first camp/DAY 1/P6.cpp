#include<stdio.h>
main()
{
    int n,i,sum=0,mean,x;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        sum = sum+x;
    }
    mean = sum/n;
    printf("%d",mean);
}
