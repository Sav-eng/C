#include<stdio.h>
main()
{
    long long ans=1;
    int n;
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        ans += (ans*3);
    }
    printf("%lld ",ans);
}
