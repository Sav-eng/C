#include<stdio.h>
main()
{
    int n,i,sum=0,a[100000],maxsum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        sum +=a[i];
        if(maxsum<sum)maxsum=sum;
        if(sum<0)sum = 0;
    }
    printf("%d",maxsum);
}
