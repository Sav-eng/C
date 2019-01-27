#include<stdio.h>
int abs(int a)
{
    if(a>0)return a;
    else
    return -a;
}
main()
{
    int a;
    scanf("%d",&a);
    printf("%d",abs(a));
}
