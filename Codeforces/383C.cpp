#include<bits/stdc++.h>
#define MAXN 200001
using namespace std;
int ind;
int a[MAXN];
int tree[MAXN];
int Begin[MAXN];
int End[MAXN];
bool Dis[MAXN];
vector<int>from[MAXN];
void dfs(int x)
{
    Begin[x] = ++ind;
    int i;
    for(i=0;i<from[x].size();i++)
    {
        Dis[from[x][i]] = !Dis[x];
        dfs(from[x][i]);
    }
    End[x] = ind;
}
int add(int x,int val)
{
    while(x<=MAXN)
    {
        tree[x] += val;
        x+= x&-x;
    }
}
int query(int x)
{
    int ans=0;
    while(x>0)
    {
        ans += tree[x];
        x -= x&-x;
    }
    return ans;
}
main()
{
    int n,m,i,x,y,c;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++)
    {
        scanf("%d%d",&x,&y);
        from[x].push_back(y);
    }
    dfs(1);
    /*for(i=1;i<=n;i++)printf("%d ",Begin[i]);
    printf("\n");
    for(i=1;i<=n;i++)printf("%d ",Dis[i]);
    printf("\n");
    for(i=1;i<=n;i++)printf("%d ",End[i]);
    printf("\n");*/
    for(i=0;i<m;i++)
    {
        scanf("%d",&c);
        if(c==1)
        {
            scanf("%d%d",&x,&y);
            if(Dis[x])
            {
                add(Begin[x],y);
                add(End[x]+1,-y);
            }
            else
            {
                add(Begin[x],-y);
                add(End[x]+1,y);
            }
        }
        else
        {
            scanf("%d",&x);
            if(Dis[x])printf("%d\n",a[x]+query(Begin[x]));
            else printf("%d\n",a[x]-query(Begin[x]));
        }
    }
}

/*

7 2
1 2 3 4 5 6 7
1 5
1 6
6 7
6 4
4 2
4 3

*/
