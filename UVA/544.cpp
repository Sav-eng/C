#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
struct node
{
    int x,y,val;
    bool operator <(node a)const
    {
        return a.val>val;
    }
};
struct node2
{
    int x,val;
};
int head[201];
int findhead(int x)
{
    if(x==head[x])return x;
    return head[x] = findhead(head[x]);
}
vector<node2>from[202];
priority_queue<node>heap;
map<string,int>mp;
string a,b,s,e;
queue<int>q;
int mem[202];
main()
{
    //freopen("out.txt","w",stdout);
    int n,m,i,val,time=0;
    int check=0;
    while(scanf("%d%d",&n,&m)&&n)
    {
        for(i=1;i<=n;i++)from[i].clear();
        check = 0;
        mp.clear();
        for(i=0;i<m;i++)
        {
            cin >> a >> b >> val;
            if(mp.find(a)==mp.end())mp[a]= ++check;
            if(mp.find(b)==mp.end())mp[b] = ++check;
            heap.push({mp[a],mp[b],val});
        }
        node t;
        cin >> s >> e;
        for(i=1;i<=n;i++)head[i] = i,mem[i] = inf;
        while(!heap.empty())
        {
            t = heap.top(); heap.pop();
            if(findhead(head[t.x])!=findhead(head[t.y]))
            {
                head[findhead(t.x)]=findhead(head[t.y]);
                from[t.x].push_back({t.y,t.val});
                from[t.y].push_back({t.x,t.val});
            }
        }
        int t2;
        q.push(mp[s]);
        //mem[mp[s]] = 0;
        while(!q.empty())
        {
            t2 = q.front(); q.pop();
            for(i=0;i<from[t2].size();i++)
            {
                //printf("%d-->%d\n",t2,from[t2][i].x);
                if(mem[from[t2][i].x]==inf)
                {
                    mem[from[t2][i].x] = min(mem[t2],from[t2][i].val);
                    q.push(from[t2][i].x);
                }
            }
            //printf("mem[%d] = %d\n",t2,mem[t2]);
        }
        //if(time)printf("\n");
        printf("Scenario #%d\n",++time);
        printf("%d tons\n\n",mem[mp[e]]);
    }
}
