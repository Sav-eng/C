#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
struct node
{
    int x,y,val;
    node(int _x = 0,int _y = 0,int _val = 0)
    {
        x = _x; y = _y; val = _val;
    }
};
int n,m,k;
int ans[1005];
int head[1005];
bool vis[1005];
vector<node> from[1005];
vector<node> a;
bool cmp(node a,node b)
{
    return a.val<b.val;
}
int findhead(int x)
{
    if(head[x]==x) return x;
    return head[x] = findhead(head[x]);
}
void dfs(int x)
{
    int i;
    vis[x] = true;
    for(i=0;i<from[x].size();i++)
    {
        if(!vis[from[x][i].x])
        {
            ans[from[x][i].x] = ans[x]+from[x][i].val;
            dfs(from[x][i].x);
        }
    }
}
main()
{
    int i,j,x,y,val;
    scanf("%d%d",&n,&k);
    for(i=1;i<=k;i++)
    {
        for(j=1;j<=k;j++)
        {
            scanf("%d",&x);
            if(i==j) continue;
            a.push_back(node(i,j,x));
        }
    }
    for(i=1;i<=k;i++) head[i] = i;
    m = a.size();
    sort(&a[0],&a[m],cmp);
    for(i=0;i<m;i++)
    {
        x = a[i].x; y = a[i].y; val = a[i].val;
        if(findhead(x)!=findhead(y) && from[x].size()<2 && from[y].size()<2)
        {
            head[findhead(x)] = findhead(y);
            from[x].push_back(node(y,0,val));
            from[y].push_back(node(x,0,val));
        }
    }
    for(i=1;i<=k;i++)
    {
        if(from[i].size()==1) x = i;
    }
    dfs(x);
    for(i=1;i<=k;i++) printf("%d\n",ans[i]);
}
