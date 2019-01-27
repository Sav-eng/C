#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+1;
const int inf = 1e9;
int head[MAXN];
pair<int,int> x[MAXN];
int findhead(int x)
{
    if(x==head[x])return x;
    return head[x] = findhead(head[x]);
}
main()
{
    int n,i,a,b;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x[i].first);
        x[i].second = i;
    }
    sort(x+1,x+n+1);
    for(i=1;i<=n;i++)head[i] = i;
    for(i=0;i<n-2;i++)
    {
        scanf("%d%d",&a,&b);
        if(findhead(a)!=findhead(b))head[findhead(a)] = findhead(b);
    }
    int ans = inf;
    for(i=1;i<=n;i++)
    {
        if(i>1)
        {
            if(findhead(x[i].second)!=findhead(x[i-1].second))ans = min(ans,x[i].first-x[i-1].first);
        }
        if(i<n)
        {
            if(findhead(x[i].second)!=findhead(x[i+1].second))ans = min(ans,x[i+1].first-x[i].first);
        }
    }
    printf("%d",ans);
}
