#include<stdio.h>
#include<queue>
using namespace std;
struct node
{
    int x,y,val;
    node(int _x=0,int _y=0,int _val=0)
    {
        x = _x;
        y = _y;
        val = _val;
    }
    bool operator <(node a)const
    {
        return a.val<val;
    }
};
int head[100];
int root(int x)
{
    if(x!=head[x])return head[x] = root(head[x]);
    else return x;
}
priority_queue<node>heap;
main()
{
    int n,m;
    int i,x,y,z;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        heap.push(node(x,y,z));
    }
    for(i=0;i<n;i++)head[i]=i;
    node t;
    int sum=0;
    while(!heap.empty())
    {
        t = heap.top();
        //printf("a");
        heap.pop();
        if(root(head[t.x])!=root(head[t.y]))
        {
            head[root(t.x)] = head[root(t.y)];
            sum += t.val;
        }
    }
    printf("%d",sum);

}
/*
7 9
0 1 7
0 2 2
1 2 3
1 3 5
2 4 1
3 4 1
3 6 3
4 5 2
5 6 2
*/
