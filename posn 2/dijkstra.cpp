#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
struct node
{
    int a,val;
    bool operator <(node a)const
    {
        return a.val<val;
    }
    node(int _a = 0,int _val = 0)
    {
        a =_a;
        val = _val;
    }
};
vector<node>from[100];
priority_queue<node>heap;
node t;
main()
{
    int n,m,s,e;
    int mem[10];
    int i,x,y,z;
    scanf("%d %d",&n,&m);
    scanf("%d%d",&s,&e);
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        from[x].push_back({y,z});
    }
    heap.push(node(s,0));
    for(i=0;i<n;i++)mem[i] = 5000;
    mem[s]=0;
    while(1)
    {
        t = heap.top();
        heap.pop();
        if(t.a==e)
        {
            printf("%d",t.val);
            break;
        }
        for(i=0;i<from[t.a].size();i++)
        {
            if(mem[from[t.a][i].a]>from[t.a][i].val + mem[t.a])
            {
                mem[from[t.a][i].a] = from[t.a][i].val + mem[t.a];
                heap.push(node(from[t.a][i].a,mem[from[t.a][i].a]));
            }
        }
    }

}
/*
7 7
0 5
0 1 7
0 2 2
2 1 3
1 3 5
3 4 1
4 5 2
3 6 3
*/
