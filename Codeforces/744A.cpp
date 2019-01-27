#include<bits/stdc++.h>
using namespace std;
int head[1001];
int Size[1001];
void Unionfind(int X,int Y)
{
    head[X] = Y;
}
int Allpair(int n)
{
    return n*(n-1)/2;
}
int findhead(int x)
{
    if(x==head[x])return x;
    return head[x] = findhead(head[x]);
}
int x[1001];
main()
{
    int n,m,k,i,j,a,b;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<k;i++)scanf("%d",&x[i]);
    for(i=1;i<=n;i++)head[i]=i;
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&a,&b);
        int X = findhead(a),Y = findhead(b);
        if(X!=Y)Unionfind(X,Y);
    }
    int Leftover = n;
    int ans=0;
    int _max=0;
    for(i=1;i<=n;i++)
    {
        int X = findhead(i);
        Size[X]++;
    }
    for(i=0;i<k;i++)
    {
        int X = findhead(x[i]);
        _max = max(_max,Size[X]);
        ans += Allpair(Size[X]);
        Leftover -= Size[X];
    }
    ans -= Allpair(_max);
    ans += Allpair(_max+Leftover);
    ans -=m;
    printf("%d",ans);
}
