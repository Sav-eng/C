#include<stdio.h>
main()
{
    int i,max=-9999999,min=9999999,a[10];
    for(i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<10;i++)
    {
        if(max<a[i])max = a[i];
        if(min>a[i])min = a[i];

    }
    printf("%d %d",max,min);
}
