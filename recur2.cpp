#include<stdio.h>
int n;
int func(int x,int sum)
{
    int i;
    if(sum==0)
    {
        printf("%d",x);
    }
    else
    {
        for(i=1;i<=n;i++)
        {
            func(n-i,sum-i);
        }
    }
}
main()
{
    int sum=n;
    scanf("%d",&n);
    func(n,sum);
}
