#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
struct node
{
    int x,y,val,ord;
    bool operator <(node a)const
    {
        return a.val<val;
    }
};
int head[3001];
int findhead(int x)
{
    if(x==head[x])return x;
    return head[x] = findhead(head[x]);
}
int a[3001];
int b[3001];
int val[3001];
int add[3001];
priority_queue<node>heap;
main()
{
    //freopen("out.txt","w",stdout);
    int T,n,m,i,j,ans,sum,check;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=m;i++)
        {
            scanf("%d%d%d",&a[i],&b[i],&val[i]);
            heap.push({a[i],b[i],val[i],i});
            //printf("%d %d\n",n,m);
        }
        ans = 0;
        for(i=1;i<=n;i++)head[i]=i;
        node t;
        check=0;
        while(!heap.empty())
        {
            t = heap.top(); heap.pop();
            if(findhead(head[t.x])!=findhead(head[t.y]))
            {
                head[findhead(t.x)]=findhead(head[t.y]);
                add[check++]=t.ord;
                ans += t.val;
            }
        }
        printf("%d ",ans);
        check = 0;
        ans = inf;
        for(i=0;i<n-1;i++)
        {
            for(j=1;j<=m;j++)if(j!=add[i])heap.push({a[j],b[j],val[j],j});
            for(j=1;j<=n;j++)head[j] = j;
            sum = 0;
            check = 0;
            while(!heap.empty())
            {
                t = heap.top(); heap.pop();
                if(findhead(head[t.x])!=findhead(head[t.y]))
                {
                    check++;
                    head[findhead(t.x)]=findhead(head[t.y]);
                    sum+=t.val;
                }
            }
            if(check==n-1)ans = min(ans,sum);
        }
        printf("%d\n",ans);
    }
}
