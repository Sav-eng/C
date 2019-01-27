#include<stdio.h>
main()
{
    int n,i,j,a[100],max=-99999,sum=1,count=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum*=a[i];
        if(max<a[i])max=a[i];
    }
    for(i=max;i<sum;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i%a[j]==0)count++;
        }
        if(count==n)break;
        count =0;
    }
    printf("%d",i);
}
