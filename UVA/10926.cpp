#include<bits/stdc++.h>
using namespace std;
int mem[101];
bool vis[101];
vector<int>a[101];
int f(int x)
{
    int n=a[x].size(),i,ans=0;
    vis[x]=1;
    for(i=0;i<n;i++)
    {
        if(!vis[a[x][i]])ans += f(a[x][i])+1;
    }
    return ans;
}
main()
{
    int n,i,j,ans=0,m,t;
    while(scanf("%d",&n)&&n)
    {
        memset(mem,0,sizeof(mem));
        ans=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&m);
            a[i].clear();
            for(j=0;j<m;j++)
            {
                scanf("%d",&t);
                a[i].push_back(t);
            }
        }
        t = 0;
        int _max =0;
        for(i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis));
            t = f(i);
            //printf("f(%d) = %d\n",i,t);
            if(_max<t)
            {
                _max = t;
                ans = i;
            }
        }
        printf("%d\n",ans);
    }
}
/*

9
1 2
1 3
1 4
0
2 6 7
1 8
1 8
0
2 6 7
0

*/
