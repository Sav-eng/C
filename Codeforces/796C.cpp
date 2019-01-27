#include<bits/stdc++.h>
#define inf 2e9
using namespace std;
long long limit=1;
int tree[2000001];
int tab[300002];
void init(int x)
{
    while(limit <=x)limit*=2;
}
void update(int x,int val)
{
    x+=limit;
    tree[x]=val;
    while(x>0)
    {
        x/=2;
        tree[x] = max(tree[x*2],tree[x*2+1]);
    }
}
int rmq(int l,int r)
{
    l+=limit;
    r+=limit;
    int ans = -inf;
    while(l<r)
    {
        if(l%2!=0)ans = max(ans,tree[l++]);
        if(r%2==0)ans = max(ans,tree[r--]);
        l/=2;
        r/=2;
    }
    if(l==r)ans = max(ans,tree[l]);
    return ans;
}
queue<int>q;
vector<int>from[300002];
main()
{
    int n,i,j,a,b,ans=inf;
    scanf("%d",&n);
    init(n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&tab[i]);
        tab[i] +=2;
        update(i,tab[i]);
    }
    for(i=0;i<n-1;i++)
    {
        scanf("%d%d",&a,&b);
        from[a].push_back(b);
        from[b].push_back(a);
    }
    for(i=1;i<=n;i++)
    {
        q.push(i);
        update(i,tab[i]-2);
        for(j=0;j<from[i].size();j++)
        {
            q.push(from[i][j]);
            update(from[i][j],tab[from[i][j]]-1);
        }
        ans = min(ans,rmq(1,n));
        while(!q.empty())
        {
            update(q.front(),tab[q.front()]);
            q.pop();
        }
    }
    printf("%d",ans);
}
/*
3
8 7 7
1 2
2 3





*/
