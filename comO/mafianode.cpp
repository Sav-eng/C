#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+2;
const int inf = 1e9;
pair<int,int> tree[4*MAXN];
int check[MAXN];
int limit;
void update(int x,int val)
{
    x+=limit;
    tree[x].first+=val;
    while(x>0)
    {
        x>>=1;
        tree[x] = max(tree[x<<1],tree[x<<1|1]);
    }
}
main()
{
    int n,m,k,i,a,b;
    char op;
    scanf("%d%d%d",&n,&m,&k);
    limit = 1;
    while(limit<n)limit<<=1;
    for(i=limit;i<2*limit;i++)tree[i].second = i-limit+1;
    for(i=0;i<n;i++)update(i,0);
    for(i=0;i<m+k;i++)
    {
        scanf(" %c",&op);
        if(op=='L')
        {
            scanf("%d%d",&a,&b);
            a--,b--;
            update(b,1);
        }
        else if(op=='C')
        {
            scanf("%d%d",&a,&b);
            a--,b--;
            update(b,3);
        }
        else if(op=='R')
        {
            printf("%d\n",tree[1].second);
        }
        else//delete
        {
            update(tree[1].second-1,-inf);
        }
    }
}
