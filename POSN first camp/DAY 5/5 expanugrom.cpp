#include<stdio.h>
#include<math.h>
int fact(int x)
{
    int i;
    long long sum=1;
    for(i=1;i<=x;i++)
    {
        sum = sum*i;
    }
    return sum;
}
main()
{
    int x,n,i;
    double sum;
    scanf("%d %d",&x,&n);
    for(i=0;i<n;i++)
    {
        sum = sum + pow(x,i)/fact(i);
        printf("%lld \n",fact(i));
        printf("%lld %d\n",fact(i),i);
    }
    printf("%lf",sum);

}
