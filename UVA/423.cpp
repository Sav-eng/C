#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
struct node
{
    int x,val;
    bool operator <(node a)const
    {
        return a.val<val;
    }
};
int mem[101];
vector<node>from[101];
priority_queue<node>heap;
main()
{
    int n,i,j,x,k;
    char a[101];
    while(scanf("%d",&n)!= EOF)
    {
        for(i=1;i<=n;i++)from[i].clear();
        for(i=2;i<=n;i++)
        {
            for(j=1;j<i;j++)
            {
                scanf(" %s",&a);
                if(a[0]=='x')continue;
                x = 0;
                for(k=0;k<strlen(a);k++)
                {
                    x*=10;
                    x+=a[k]-'0';
                }
                //printf("[%d]",x);
                from[i].push_back({j,x});
                from[j].push_back({i,x});
            }
        }
        /*for(i=1;i<=n;i++)
        {
            printf("%d--->",i);
            for(j=0;j<from[i].size();j++)
            {
                printf("%d[%d] ",from[i][j].x,from[i][j].val);
            }
            printf("\n");
        }*/
        for(i=1;i<=n;i++)mem[i] = inf;
        mem[1]=0;
        heap.push({1,0});
        node t;
        int ans=0;
        while(!heap.empty())
        {
            t = heap.top(); heap.pop();
            for(i=0;i<from[t.x].size();i++)
            {
                if(mem[from[t.x][i].x] > t.val+from[t.x][i].val)
                {
                    mem[from[t.x][i].x] = t.val+from[t.x][i].val;
                    heap.push({from[t.x][i].x,mem[from[t.x][i].x]});
                }
            }
            //printf("mem[%d] = %d\n",t.x,mem[t.x]);
            ans = max(ans,mem[t.x]);
        }
        printf("%d\n",ans);
    }
}
