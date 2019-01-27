#include<bits/stdc++.h>
#define inf 1e9
#define MAXN 300000
using namespace std;
int limit=1;
int tree[MAXN*4];
void update(int x,int val)
{
    x +=limit;
    tree[x] = val;
    while(x>1)
    {
        x/=2;
        tree[x] = max(tree[x<<1],tree[x<<1|1]);
    }
}
int rmq(int l,int r)
{
    int ans = -inf;
    l+=limit,r+=limit;
    while(l<r)
    {
        if(l%2!=0)ans = max(ans,tree[l++]);
        if(r%2==0)ans = max(ans,tree[r--]);
        l/=2; r/=2;
    }
    if(l==r)ans = max(ans,tree[l]);
    return ans;
}
main()
{
    int n,m,i,x,y;
    char a;
    scanf("%d%d",&n,&m);
    while(limit<n)limit = limit<<1;
    for(i=0;i<m;i++)
    {
        scanf(" %c",&a);
        scanf("%d%d",&x,&y);
        if(a=='U')update(x,y);
        else printf("%d\n",rmq(x,y));
    }
}
