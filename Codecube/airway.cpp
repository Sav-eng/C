#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#define inf 1e9
using namespace std;
struct node
{
    int x,val,time;
    bool operator <(node a)const
    {
        return val<a.val;
    }
};
vector<node>from[1005];
int mem[1005];
priority_queue<node>heap;
main()
{
    int n,m,s,e,ls,le,lv,lk,i,a,b,val;
    scanf("%d%d",&n,&m);
    scanf("%d%d",&s,&e);
    scanf("%d%d%d%d",&ls,&le,&lv,&lk);
    from[ls].push_back({le,lv,lk});
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&a,&b,&val);
        from[a].push_back({b,val,inf});
    }
    heap.push({s,0,0});
    node t;
    for(i=0;i<n;i++)mem[i]=inf;
    mem[s] = 0;
    while(!heap.empty())
    {
        t = heap.top(); heap.pop();
        //printf("%d",t.x);
        for(i=0;i<from[t.x].size();i++)
        {
            //printf("from[%d][%d].time = %d mem[%d] = %d from[%d][%d].val = %d\n",t.x,i,from[t.x][i].time,t.x,mem[t.x],t.x,i,from[t.x][i].val);
            if(from[t.x][i].time >= mem[t.x] && mem[from[t.x][i].x] > mem[t.x]+from[t.x][i].val)
            {
                mem[from[t.x][i].x] = mem[t.x] + from[t.x][i].val;
                heap.push({from[t.x][i].x,mem[from[t.x][i].x],0});
            }
        }
    }
    //for(i=0;i<n;i++)printf("%d ",mem[i]);
    printf("%d",mem[e]);
}
/*

4 4
0 3
1 2 -3 3
0 1 5
0 3 10
1 3 6
2 3 5

*/
