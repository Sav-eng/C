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
priority_queue<node>heap;
int head[1000001];
int findhead(int x)
{
    if(x==head[x])return x;
    else return head[x] = findhead(head[x]);
}
main()
{
    //freopen("out.txt","w",stdout);
    int n,m,i,a,b,val,k,ans,sum,T=0,check;
    while(scanf("%d",&n)!=EOF)
    {
        if(T++)printf("\n");
        sum = 0;
        while(!heap.empty())heap.pop();
        for(i=0;i<n-1;i++)
        {
            scanf("%d%d%d",&a,&b,&val);
            heap.push({a,b,val});
            sum+=val;
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&val);
            heap.push({a,b,val});
        }
        scanf("%d",&k);
        for(i=0;i<k;i++)
        {
            scanf("%d%d%d",&a,&b,&val);
        }
        ans = 0;
        check = 0;
        node t;
        for(i=1;i<=n;i++)head[i]=i;
        while(!heap.empty())
        {
            t = heap.top(); heap.pop();
            if(findhead(head[t.x])!=findhead(head[t.y]))
            {
                check++;
                ans+=t.val;
                head[findhead(t.x)] = findhead(head[t.y]);
            }
            if(check==n-1)break;
        }
        printf("%d\n%d\n",sum,ans);
    }
}
