#include<bits/stdc++.h>
using namespace std;
int mem[100001][5];
int vis[100001];
vector<int>from[100001];
vector<int>from2[100001];
int endcycle,startcycle;
int dfs(int x,int last)
{
    vis[x]= 1;
    int i;
    for(i=0;i<from[x].size();i++)
    {
        if(!vis[from[x][i]])
        {
            from2[x].push_back(from[x][i]);
            dfs(from[x][i],x);
        }
        else if(last != from[x][i] && vis[from[x][i]]==1)
        {
            endcycle = x;
            startcycle = from[x][i];
        }
    }
    vis[x]=2;
}
/*
0 choose
1 not choose
2 choose and not
3 not and not
*/
int solve(int x,int check)
{
    if(mem[x][check]==-1)
    {
        int i;
        if(check==1 || check==3)mem[x][check]=0;
        else mem[x][check]=1;
        for(i=0;i<from2[x].size();i++)
        {
            //printf("%d-->%d\n",x,from2[x][i]);
            if(check==0)mem[x][check]+= (x==startcycle)? solve(from2[x][i],3):solve(from2[x][i],1);
            else if(check==1)mem[x][check]+= max(solve(from2[x][i],0),solve(from2[x][i],1));
            else if(check==2)mem[x][check] +=  solve(from2[x][i],3);
            else mem[x][check]+= (from2[x][i]==endcycle)? solve(from2[x][i],3):max(solve(from2[x][i],2),solve(from2[x][i],3)) ;
            //printf("mem[%d][%d] = %d %d--->%d\n",x,check,mem[x][check],x,from2[x][i]);
        }
    }
    return mem[x][check];
}
main()
{
    int Q,ans=0;
    scanf("%d",&Q);
    while(Q--)
    {
        int n,i,a;

        scanf("%d",&n);
        memset(vis,0,sizeof(vis));
        memset(mem,-1,sizeof(mem));
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a);
            from[a].push_back(i);
            from[i].push_back(a);
            //mem[i][0] = mem[i][1] = mem[i][2] = mem[i][3] = -1;
        }
        ans = 0;
        for(i=1;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,0);
                ans +=max(solve(i,0),solve(i,1));
            }
        }
        printf("%d\n",n-ans);
        for(i=0;i<=n;i++)from[i].clear(),from2[i].clear();
    }
}
