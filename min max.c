#include<stdio.h>
main()
{
    int n,a[50000],i,min,max;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        if(max < a[i])max = a[i];
        if(min > a[i])min = a[i];
    }
    printf("%d %d",min,max);
}
