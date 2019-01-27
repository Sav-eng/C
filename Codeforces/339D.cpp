#include<bits/stdc++.h>
#define MAXN 1<<17
using namespace std;
int n,limit=1;
int tree[4*MAXN];
void update(int x,int val)
{
    bool check=0;
    x+=limit;
    tree[x] = val;
    while(x>1)
    {
        x/=2;
        if(!check)tree[x] = tree[x<<1]|tree[(x<<1)+1];
        else tree[x] = tree[x<<1]^tree[(x<<1)+1];
        check = !check;
    }
}
main()
{
    int a,b,T,i;
    scanf("%d%d",&n,&T);
    n = 1<<n;
    while(limit<=n)limit*=2;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        update(i,a);
    }
    //for(i=1;i<=4*n;i++)printf("%d ",tree[i]);
    while(T--)
    {
        scanf("%d%d",&a,&b);
        update(a-1,b);
        printf("%d\n",tree[1]);
    }
}
