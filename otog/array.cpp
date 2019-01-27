#include<bits/stdc++.h>
using namespace std;
const int MAXN = INT_MAX;
map<int,long long> tree;
void update(long long x,int val)
{
    while(x<MAXN)
    {
        tree[x] += val;
        x += x&-x;
    }
}
long long query(int x)
{
    long long sum = 0;
    while(x>0)
    {
        sum += tree[x];
        x -= x&-x;
    }
    return sum;
}
main()
{
    int n,T,l,r,val,operation;
    scanf("%d%d",&n,&T);
    while(T--)
    {
        scanf("%d",&operation);
        if(operation == 0)
        {
            scanf("%d%d%d",&l,&r,&val);
            l++,r++;
            update(l,val);
            update(r+1,-val);
        }
        else
        {
            scanf("%d%d",&l,&r);
            l++,r++;
            printf("\t%lld\n",query(r)-query(l-1));
        }
    }
}
