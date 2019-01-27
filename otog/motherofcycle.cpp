#include<bits/stdc++.h>
using namespace std;
int vis[300010];
vector<int>from[300010];
stack<int>st;
int Cycle[300010];
int ANS[300010];
int cnt;
void dfs(int x,int last)
{
    vis[x] = 1;
    st.push(x);
    for(int i=0;i<from[x].size();i++)
    {
        if(vis[from[x][i]] && last!=from[x][i])
        {
            int t = from[x][i];
            while(!st.empty())
            {
                Cycle[st.top()]=1;
                //printf("%d ",st.top());
                if(st.top()==t)break;
                //cycle[cnt].push_back(st.top());
                st.pop();
            }
            while(!st.empty())st.pop();
            cnt++;
        }
        else if(from[x][i]!=last)dfs(from[x][i],x);
    }
    if(!st.empty())st.pop();
}
int dfs2(int x,int last)
{
    int ans=1;
    vis[x] = 1;
    for(int i=0;i<from[x].size();i++)
    {
        if(from[x][i]!=last && !Cycle[from[x][i]])ans += dfs2(from[x][i],x);
    }
    return ans;
}
main()
{
    int m,i,a,b,_max=0,j;
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&a,&b);
        from[a].push_back(b);
        from[b].push_back(a);
        _max = max(_max,max(a,b));
    }
    memset(vis,0,sizeof(vis));
    cnt = 0;
    //find cycle
    for(i=0;i<_max;i++) if(!vis[i])dfs(i,-1);
    //check cycle
    memset(vis,0,sizeof(vis));
    for(i=0;i<=_max;i++)
    {
        if(Cycle[i])
        {
            ANS[i] = dfs2(i,-1);
            //printf("%d ",i);
        }
    }//printf("\n");
    for(i=0;i<=_max;i++)
    {
        if(ANS[i])printf("%d %d\n",i,ANS[i]-1);
    }
}
/*

8
1 2
2 3
3 4
2 5
5 8
5 6
6 7
7 8


*/
