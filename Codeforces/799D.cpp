#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
    return x>y;
}
int ans;
int a,b,n,w,h;
int x[100001];
void f(long long X,long long Y,int now)
{
    if(X>=a && Y>=b)
    {
        ans = min(ans,now);
        return;
    }
    if(now==n)
    {
        return;
    }
    if(x[now]==2)
    {
        while(X<a)
        {
            X<<=1;
            now++;
        }
        while(Y<b)
        {
            Y<<=1;
            now++;
        }
        ans = min(now,ans);
    }
    if(X<a)f(X*x[now],Y,now+1);
    if(Y<b)f(X,Y*x[now],now+1);
}
main()
{
    int i;
    scanf("%d%d%d%d%d",&a,&b,&w,&h,&n);
    for(i=0;i<n;i++)scanf("%d",&x[i]);
    sort(&x[0],&x[n],cmp);
    ans = n+1;
    f(w,h,0);
    f(h,w,0);
    printf("%d",(ans==n+1)?-1:ans);
}
