#include<stdio.h>
#include<queue>
using namespace std;
struct node
{
    int x,y;
};
int n,m;
bool check(int x,int y)
{
    if(x>=n || y>=m || y<0 || x<0)return 0;
    return 1;
}
queue<node>q;
node t;
int a[1005][1005];
int mem[1005][1005];
int go[1005][1005];
int cx[] = {0,0,1,-1};
int cy[] = {1,-1,0,0};
main()
{
    int i,j,ans;
    scanf("%d%d",&n,&m);
    ans = n*m;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j] == 0)
            {
                go[i][j] = 1;
                ans--;
                q.push({i,j});
            }
        }
    }
    while(!q.empty())
    {
        t = q.front();
        q.pop();
        for(i=0;i<4;i++)
        {
            if(go[t.x+cx[i]][t.y+cy[i]] ==0 && check(t.x+cx[i],t.y+cy[i]))
            {
                mem[t.x+cx[i]][t.y+cy[i]] = mem[t.x][t.y] +1;
                go[t.x+cx[i]][t.y+cy[i]] = 1;
                if(mem[t.x+cx[i]][t.y+cy[i]] - a[t.x+cx[i]][t.y+cy[i]] < 0)
                {
                    ans--;
                    //printf("%d %d\n",t.x+cx[i],t.y+cy[i]);
                    q.push({t.x+cx[i],t.y+cy[i]});
                }
            }
        }
    }
    printf("%d",ans);

}
/*

4 4
0 1 3 2
0 3 1 1
0 1 1 1
0 4 1 9


*/
