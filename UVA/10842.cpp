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
int head[101];
int findhead(int x)
{
    if(x==head[x])return x;
    else return head[x] = findhead(head[x]);
}
priority_queue<node>heap;
main()
{
    int T,n,m,i,ans=0,check=0,a,b,val;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&val);
            heap.push({a,b,val});
        }
        for(i=0;i<n;i++)head[i]=i;
        ans = 0;
        node t;
        while(!heap.empty())
        {
            t = heap.top(); heap.pop();
            if(findhead(head[t.x])!=findhead(head[t.y]))
            {
                head[findhead(t.x)]=findhead(head[t.y]);
                ans = t.val;
            }
        }
        printf("Case #%d: %d\n",++check,ans);
    }
}
