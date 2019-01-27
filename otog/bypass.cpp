#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+1;
int mem[MAXN];
vector<int>from[MAXN];
long long ans;
int n;
int dfs(int u,int last)
{
    vector<int>_max,pref,suff;
    mem[u] = 1;
    int ret = 0;
    for(int v: from[u])
    {
        if(v==last)continue;
        _max.push_back(dfs(v,u));
        mem[u] += mem[v];
        ret = max(ret,mem[v]);
    }
    for(int v: from[u])
    {
        if(v==last)continue;
        if(pref.empty())pref.push_back(mem[v]);
        else pref.push_back(max(pref.back(),mem[v]));
    }
    for(int i = from[u].size()-1;i>=0;i--)
    {
        int v = from[u][i];
        //if(v==last)continue;
        if(suff.empty())suff.push_back(mem[v]);
        else suff.push_back(max(suff.back(),mem[v]));
    }
    reverse(suff.begin(),suff.end());
    for(int i=0;i<_max.size();i++)
    {
        ans = max(ans,(long long)(n-mem[u])*_max[i]);
        if(i)ans = max(ans,(long long)pref[i-1]*_max[i]);
        if(i+1<_max.size())ans = max(ans,(long long)suff[i+1]*_max[i]);
    }
    return ret;
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int i,a,b;
    cin >> n;
    //cout << n;
    for(i=0;i<n-1;i++)
    {
        cin >> a >> b;
        //cout << a << b;
        from[a].push_back(b);
        from[b].push_back(a);
    }
    //cout << a;
    dfs(1,0);
    cout << ans;
}

