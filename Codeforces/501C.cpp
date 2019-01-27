#include<bits/stdc++.h>
using namespace std;
struct node
{
    int val,ind;
};
queue<node>q;
int degree[1000001];
int value[1000001];
int head[1000001];
int tab1[1000001];
int tab2[1000001];
main()
{
    int n,i;
    int cnt = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&degree[i],&value[i]);
        if(degree[i]==1)q.push({value[i],i});
        head[i] = i;
    }
    node t;
    while(!q.empty())
    {
        t = q.front(); q.pop();//if degree = 1 mean sum of XOR = val of v
        int v = t.val;
        int u = t.ind;
        if(head[u]!=v)
        {
            tab1[cnt] = u;
            tab2[cnt++] = v;
        }
        head[v] = u;
        degree[v]--;
        value[v] ^= u;
        if(degree[v]==1)q.push({value[v],v});
    }
    printf("%d\n",cnt);
    for(i=0;i<cnt;i++)printf("%d %d\n",tab1[i],tab2[i]);
}
