#include<bits/stdc++.h>
using namespace std;
void f(int x,int y)
{
    if(vis[x]==1)
    {
        while(!st.empty())
        {
            t = st.top();
            st.pop();
            cycle[t] = true;
            if(x==t)break;
        }
    }
    vis[x]= 1;
    st.push(x);
    for(i=0;i<from[x].size();i++)
    {
        if(from[x][i] != y && vis[from[x][i]] <= 1)dfs(from[x][i],x);
    }
    )
    vis[x] = 2;
    if(!st.empty())st.pop();
}
main()
{
    scanf("%d",&n,&s);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        from[a].push_back(b);
        from[b].push_back(a);
        if(a==s)connect[b] = true;
        else if(b==s)connect[a] = true;
    }
    dfs(1,0);
    ans=0;
    memset(vis,0,sizeof(mem));
    if(cycle[s])
    {

    }
    else
    {

    }
}
