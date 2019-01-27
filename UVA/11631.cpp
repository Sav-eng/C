#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y,val;
    bool operator <(node a)const
    {
        return a.val<val;
    }
};
int head[2000005];
int findhead(int x)
{
    if(x==head[x])return head[x];
    else return head[x] = findhead(head[x]);
}
priority_queue<node>heap;
main()
{
    int n,m,i,a,b,c,ans,sum;
    node t;
    while(scanf("%d%d",&n,&m) &&(n || m))
    {
        ans = 0;
        sum=0;
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            sum+=c;
            heap.push({a,b,c});
        }
        for(i=0;i<n;i++)head[i] = i;
        while(!heap.empty())
        {
            t = heap.top();
            heap.pop();
            if(findhead(head[t.x])!=findhead(head[t.y]))
            {
                head[findhead(t.x)] = findhead(head[t.y]);
                ans+= t.val;
            }
        }
        printf("%d\n",sum-ans);
    }
}
