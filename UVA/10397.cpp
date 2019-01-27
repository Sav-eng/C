#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y;
    double val;
    bool operator <(node a)const
    {
        return a.val<val;
    }
};
int head[751];
int findhead(int x)
{
    if(x==head[x])return x;
    return head[x] = findhead(head[x]);
}
priority_queue<node>heap;
int a[751];
int b[751];
main()
{
    int i,n,j,m,c,d;
    double ans;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)heap.push({i,j,(double)sqrt(((a[i]-a[j])*(a[i]-a[j]))+((b[i]-b[j])*(b[i]-b[j])))});
            head[i] = i;
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&c,&d);
            head[findhead(c)] = findhead(head[d]);
        }
        ans = 0;
        node t;
        while(!heap.empty())
        {
            t = heap.top();heap.pop();
            if(findhead(head[t.x])!=findhead(head[t.y]))
            {
                head[findhead(t.x)]=findhead(head[t.y]);
                ans+=t.val;
            }
        }
        printf("%.2lf\n",ans);
    }
}
