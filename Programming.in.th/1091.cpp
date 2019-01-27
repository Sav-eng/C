#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
using namespace std;
queue<int>q;
stack<int>st;
vector<int>from[300005];
int mem[300005];
int check[300005];
int dfs(int x)
{
    check[x] =1;
    int i;
    for(i=0;i<from[x].size();i++)
    {
        if(check[from[x][i]]==0)dfs(from[x][i]);
    }
    st.push(x);
}
main()
{
    int n,a,b,i,t,_max=0,ans=0;
    scanf("%d",&n);
    for(i=0;i<n-1;i++)
    {
        scanf("%d%d",&a,&b);
        from[min(a,b)].push_back(max(a,b));
    }
    for(i=1;i<=n;i++)
    {
        if(check[i]==0)
        {
            dfs(i);
        }
    }
    while(!st.empty())
    {
        t = st.top();
        st.pop();
        for(i=0;i<from[t].size();i++)
        {
            mem[from[t][i]] = max(mem[from[t][i]],mem[t]+1);
            ans = max(mem[from[t][i]],ans);
        }
    }
    printf("%d",ans+1);
    //for(i=1;i<=n;i++)printf("%d ",mem[i]);
}

