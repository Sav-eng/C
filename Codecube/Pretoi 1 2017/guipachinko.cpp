#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
struct node
{
    int x,y;
    bool operator <(node a)const
    {
        return a.y>y;
    }
};
bool cmp(node x,node y)
{
    return x.y>y.y;
}
priority_queue<node>heap;
int n,m,s;
vector<int>from[100001];
int mem[100001];
int tab[100001];
long long sum[100001];
int dfs(int x)
{
    if(from[x].size()==0)return mem[x] = x;
    else if(!mem[x])
    {
        int i;
        mem[x] = x;
        for(i=0;i<from[x].size();i++)
        {
            //printf("%d-->%d\n",x,from[x][i]);
            mem[x] = max(mem[x],max(dfs(from[x][i]),from[x][i]));
        }
    }
    return mem[x];
}
int cnt=0;
void pre(int x)
{
    tab[cnt--] = x;
    vector<node>go;
    int _max =0,i;
    for(i=0;i<from[x].size();i++)
    {
        //printf("%d-->%d (%d)\n",x,from[x][i],mem[from[x][i]]);
        go.push_back({from[x][i],mem[from[x][i]]});
    }
    if(go.size()==0)return;
    sort(go.begin(),go.end(),cmp);
    for(i=0;i<go.size();i++)pre(go[i].x);
}
main()
{
    int i,a,s;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        if(a==0)s = i;
        from[a].push_back(i);
    }
    dfs(s);
    //for(i=1;i<=n;i++)printf("mem[%d] = %d\n",i,mem[i]);
    //printf("-------------------------------------------------------\n");
    cnt =n;
    pre(s);
    //for(i=0;i<=n;i++)printf("tab[%d] = %d\n",i,tab[i]);
    for(i=1;i<=n;i++)
    {
        sum[i] = sum[i-1]+tab[i];
    }
    int now;
    now = 0;
    int x;
    for(i=0;i<m;i++)
    {
        scanf("%d",&a);
        if(a==1)
        {
            scanf("%d",&x);
            now+=x;
            printf("%d\n",tab[now]);
        }
        else if(a==2)
        {
            scanf("%d",&x);
            now-=x;
        }
        else
        {
            printf("%lld\n",sum[now]);
        }
    }

}
