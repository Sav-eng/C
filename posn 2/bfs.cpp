#include<stdio.h>
#include<queue>
using namespace std;
struct node
{
    int x,y,z;
    node(int _x=0,int _y=0,int _z = 0)
    {
        x = _x;
        y = _y;
        z = _z;
    }
};
queue<node>x;
int a[100][100];
int visit[100][100];
main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    x.push(node(0,0,1));
    node t;
    while(!x.empty())
    {
         t = x.front();
         x.pop();
         if(a[(t.x)+1][t.y]==1 && visit[(t.x)+1][t.y] == false)
         {
            x.push(node((t.x)+1,t.y,t.z+1));
            visit[t.x+1][t.y] = true;
         }
         if(a[t.x][(t.y)+1]==1 && visit[t.x][t.y+1] == false)
         {
            x.push(node(t.x,(t.y)+1,t.z+1));
            visit[t.x][t.y+1] = true;
         }
         if(t.x == n-1 && t.y == n-1)
         {
             printf("%d",t.z);
             break;
         }
    }
}
/*
5
1 1 0 0 0
0 1 1 0 0
0 0 1 1 1
1 1 1 0 1
0 0 1 1 1
*/
