#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#define inf 1e9
using namespace std;
struct node
{
    int x,val,order,pare;
    bool operator <(node a)const
    {
        if(a.val<val)return 1;
        else if(a.val == val)
        {
            return a.order < order;
        }
        return 0;
    }
};
vector<node>from[6000];
priority_queue<node>heap;
long long mem[6000][5];
int visit[6000][5];
int _max[6000][5];
main()
{
    int n,m,i,x,y,z;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        from[x].push_back({y,z,i,0});
        from[y].push_back({x,z,i,0});
    }
    for(i=0;i<=1000;i++)
    {
        mem[i][0] = inf;
        mem[i][1] = inf;
    }
    heap.push({1,0,0,0});
    mem[1][0] = 0;
    //mem[1][1]=0;
    node t;
    while(!heap.empty())
    {
        t = heap.top();
        heap.pop();
        //printf("%d",pare);
        for(i=0;i<from[t.x].size();i++)
        {
            if(mem[t.x][t.pare] + from[t.x][i].val < mem[from[t.x][i].x][!t.pare])
            {
                mem[from[t.x][i].x][!t.pare] = mem[t.x][t.pare] + from[t.x][i].val;
                _max[from[t.x][i].x][!t.pare] = max(t.order,from[t.x][i].order);
                heap.push({from[t.x][i].x,mem[from[t.x][i].x][!t.pare],_max[from[t.x][i].x][!t.pare],!t.pare});
            }
        }
    }
    if(_max[n][1] == 0 && mem[n][1] == inf)
    {
        printf("0 0");
        return 0;
    }
    printf("%d %lld",_max[n][1],mem[n][1]);
}
/*

5 10
4 5 7
2 3 1
3 5 5
2 5 5
1 4 6
1 2 1
3 4 7
1 3 7
2 4 4
1 5 8

6 7

3 1
1 2 3

1 2
1 1 2
1 1 3


*/
