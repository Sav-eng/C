#include<stdio.h>
#include<queue>
using namespace std;
struct node
{
    int a,b,c;
    bool operator <(node a)const
    {
        return a.c<c;
    }
};
int head[1000];
int root(int x)
{
    if(head[x]!=x) return root(head[x]);
    return head[x];
}
priority_queue<node>heap;
node t[1000];
main()
{
    int n,m,i,check=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&t[i].a,&t[i].b,&t[i].c);
        heap.push(t[i]);
    }
    for(i=0;i<n;i++)head[i]=i;
    node tm;
    while(!heap.empty())
    {
        tm = heap.top();
        //printf("**%d %d**\n",head[tm.a],head[tm.b]);
        if(head[tm.a]!=head[tm.b])
        {
            if(root(head[tm.b])!=root(head[tm.a]))
            {
                head[tm.b] = head[tm.a];
                check+=tm.c;
                //printf("%d %d %d\n",check,tm.b,tm.a);
            }
        }
        heap.pop();
    }
    printf("%d",check);

}
/*
6 7
1 2 5
2 3 1
2 4 3
1 4 6
3 4 4
3 5 6
4 5 2
*/
