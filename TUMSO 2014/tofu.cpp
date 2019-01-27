#include<stdio.h>
int fact(int x)
{
    int i,ans=1;
    for(i=2;i<=x;i++)ans *=i;
    return ans;
}
int combi(int n,int r)
{
    return fact(n+r)/(fact(n)*fact(r));
}
main()
{
    int n,m,checkk,k,ans=0;
    scanf("%d%d",&n,&k);
    checkk=0;
    while(n>=1 && checkk<=k)
    {
        ans += combi(n,checkk);
        n-=2;
        checkk++;
    }
    printf("%d",ans);
}
