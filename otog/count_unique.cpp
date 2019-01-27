#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e6+1;
int tree[MAXN];
int a[MAXN];
int check[MAXN];
int ans[MAXN];
int limit;
struct node
{
    int l,r,ind;
    bool operator <(node a)const
    {
        return a.r>r;
    }
};
node tab[MAXN];
void update(int x,int val)
{
    while(x<=MAXN)
    {
        tree[x] += val;
        x += x&-x;
    }
}
int query(int x)
{
    int sum = 0;
    while(x>0)
    {
        sum += tree[x];
        x -= x&-x;
    }
    return sum;
}
main()
{
    limit = 1;
    int n,m,i,j,l,r;
    scanf("%d%d",&n,&m);
    while(limit<n)limit <<=1;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&tab[i].l,&tab[i].r);
        tab[i].ind = i;
    }
    sort(tab,tab+m);
    int cnt = 0;
    for(i=1;i<=n;i++)
    {
        update(i,1);
        if(check[a[i]])
        {
            update(check[a[i]],-1);
        }
        check[a[i]] = i;
        while(tab[cnt].r==i)
        {
            //printf("%d %d %d %d\n",tab[cnt].l,tab[cnt].r,query(tab[cnt].r),query(tab[cnt].l-1));
            ans[tab[cnt].ind] = query(tab[cnt].r)-query(tab[cnt].l-1);
            cnt++;
        }
    }
    for(i=0;i<m;i++)printf("%d\n",ans[i]);
}
