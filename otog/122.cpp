#include<bits/stdc++.h>
using namespace std;
int tree[200001];
int n;
int update(int x,int val)
{
    while(x<=n)
    {
        tree[x] += val;
        x+=x&-x;
    }
}
int query(int x)
{
    int sum = 0;
    while(x>0)
    {
        sum += tree[x];
        x-= x&-x;
    }
    return sum;
}
main()
{
    int T,op,l,r,val,x;
    scanf("%d%d",&n,&T);
    while(T--)
    {
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d%d%d",&l,&r,&val);
            update(l,val);
            update(r+1,-val);
        }
        else
        {
            scanf("%d",&x);
            printf("%d\n",query(x));
        }
    }
}
