#include<bits/stdc++.h>
using namespace std;
int head[100002];
int a[100002];
int b[100002];
long long sum[100002];
int vis[100002];
vector<long long>ans;
int findhead(int x)
{
    if(head[x]==x)return x;
    return head[x] = findhead(head[x]);
}
main()
{
    int n,i;
    long long _max;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<=n;i++)scanf("%d",&b[i]);
    for(i=0;i<=n+1;i++)head[i] = i;
    _max = 0;
    for(i=n;i>0;i--)
    {
        ans.push_back(_max);
        int x = b[i];
        sum[x] = a[x];
        vis[x] = 1;
        if(vis[x+1])
        {
            sum[x] += sum[findhead(x+1)];
            head[findhead(x+1)] = x;
        }
        if(vis[x-1])
        {
            sum[x] += sum[findhead(x-1)];
            head[findhead(x-1)] = x;
        }
        _max = max(_max,sum[x]);
    }
    for(i=n-1;i>=0;i--)printf("%I64d\n",ans[i]);
}
