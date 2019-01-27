#include<stdio.h>
main()
{
    int min=999999999,max=-999999999,i,n,a[10000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        if(max<a[i])max = a[i];
        if(min>a[i])min = a[i];
    }
    printf("%d \n%d",min ,max);

}


