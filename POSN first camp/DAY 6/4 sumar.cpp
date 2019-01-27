#include<stdio.h>
float sum(int n,float a[])
{
    int sum=0;
    int i;
    for(i=0;i<n;i++)sum+=a[i];
    return sum;
}
main()
{
    int n;
    int i;
    float a[10000];
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%f",&a[i]);
    printf("%f",sum(n,a));
}

