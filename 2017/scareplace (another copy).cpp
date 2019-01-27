#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y,val;
    bool operator <(node a)const
    {
        return a.val>val;
    }
};
int head[2000002];
int findhead(int x)
{
    if(x==head[x])return x;
    return head[x] = findhead(head[x]);
}
priority_queue<node>heap;
main()
{
    int n,m,a,b,c,i;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        heap.push({a,b,c});
    }
    long long ans=0;
    node t;
    for(i=1;i<=n;i++)head[i]=i;
    while(!heap.empty())
    {
        t = heap.top(); heap.pop();
        if(findhead(head[t.x])!=findhead(head[t.y]))
        {
            head[findhead(t.x)]=findhead(head[t.y]);
            ans+=t.val-1;
        }
    }
    printf("%lld",ans);
}
