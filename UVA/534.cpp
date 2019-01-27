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
struct node2
{
    int x;
    double val;
};
int x[202];
int y[202];
int head[202];
vector<node2>from[202];
double mem[202];
priority_queue<node>heap;
queue<int>q;
int findhead(int x)
{
    if(x==head[x])return x;
    return head[x] = findhead(head[x]);
}
main()
{
    //freopen("out.txt","w",stdout);
    int n,i,j,val,check=0;
    while(scanf("%d",&n)&&n)
    {
        for(i=0;i<=n;i++)from[i].clear();
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&x[i],&y[i]);
        }
        double val;
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                val = sqrt((((x[i]-x[j])*(x[i]-x[j]))+((y[i]-y[j])*(y[i]-y[j]))));
                heap.push({i,j,val});
            }
            head[i] = i;
        }
        node t;
        while(!heap.empty())
        {
            t = heap.top(); heap.pop();
            if(findhead(head[t.x])!=findhead(head[t.y]))
            {
                head[findhead(t.x)] = findhead(head[t.y]);
                from[t.x].push_back({t.y,t.val});
                from[t.y].push_back({t.x,t.val});
                //printf("%d---%d\n",t.x,t.y);
            }
        }
        q.push(1);
        memset(mem,0,sizeof(mem));
        int t2;
        while(!q.empty())
        {
            t2 = q.front(); q.pop();
            for(i=0;i<from[t2].size();i++)
            {
                if(!mem[from[t2][i].x])
                {
                    mem[from[t2][i].x] = max(from[t2][i].val,mem[t2]);
                    q.push(from[t2][i].x);
                }
            }
            //printf("mem[%d] = %.3lf\n",t2,mem[t2]);
        }
        //if(check)printf("\n");
        printf("Scenario #%d\n",++check);
        printf("Frog Distance = %.3lf\n\n",mem[2]);
    }
}
