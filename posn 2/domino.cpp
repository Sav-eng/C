#include<stdio.h>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;
struct node
{
    int x,val;
    bool operator < (node a) const
    {
        return a.val<val;
    }
    node(int _x = 0,int _val = 0)
    {
        x = _x;
        val = _val;
    }
};
vector<node>from[10000];
priority_queue<node>heap;
int mem[10000];
main()
{
    int n,a,b,i,j,m;
    int x,y;
    node t;

    scanf("%d %d %d %d",&n,&a,&b,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&x,&y);
        from[x].push_back(y);
        from[y].push_back(x);
    }
    for(i=1;i<=m;i++) mem[i] = INT_MAX;
    heap.push(a);
    int tm;
    mem[a]=0;
    while(!heap.empty())
    {
        t = heap.top();
        //printf("t = %d",t);
        heap.pop();
        if(t.x==b)
        {
            printf("%d",t.val);
            break;
        }
        for(i=0;i<from[t.x].size();i++)
        {
            tm = mem[t.x] + from[t.x][i].x + t.x;
            //printf("mem[%d]=%d t = %d tm=%d\n",from[t][i],mem[from[t][i]],t,tm);
            if(mem[from[t.x][i].x] > tm)
            {
                mem[from[t.x][i].x] = tm;
                heap.push(node(from[t.x][i].x,mem[from[t.x][i].x]));
            }

        }
    }
    //for(i=0;i<from[1].size();i++)printf("%d",from[1][i]);
    //for(i=0;i<m;i++)printf("%d ",mem[t]);
}
/*
6 5 1 9
3 9
9 4
5 4
2 9
5 2
3 1
*/
