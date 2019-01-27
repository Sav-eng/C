#include<stdio.h>
#include<queue>
using namespace std;
struct node
{
    int x;
    int y;
    bool operator >(node a)const
    {
        return a.x<x;
    }
    node(int _x = 0,int _y = 0)
    {
        x = _x;
        y = _y;
    }
};
priority_queue<node>heap;
int val[1000005];
int head[1000005];
int x[1000005];
main()
{
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",x[i]);
    }
    for(i=0;i<m;i++)
    {
        scanf("%d",y);
        if(y==1)
        {
            scanf("%d",a);
            val[head[a]]-=x[a];
            val[a]=1;
            head[a] = a
        }
        else if(y==2)
        {
            scanf("%d%d%d%d",a,b,t,v);
            if(head[a]!=head[b])
            {
                val[head[a]]-=x[a];
                val[head[b]]+=x[a];
                head[a] = head[b];
                heap.push(node(t,v));
            }

        }
        else
        {
            scanf("%d",a);
            printf("%d",val[head[a]]);
        }
    }
}
