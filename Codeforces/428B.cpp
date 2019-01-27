#include<bits/stdc++.h>
#define MAXN 100001
#define BITMAX 30
using namespace std;
int limit=1;
int l[MAXN];
int r[MAXN];
int x[MAXN];
int a[MAXN];
int sum[MAXN];
int tree[4*MAXN];
int QS[MAXN];
void add(int x,int val)
{
    x += limit;
    tree[x] = val;
    while(x>0)
    {
        x>>=1;
        if(tree[x<<1]==0)tree[x] = tree[x<<1|1];
        else if(tree[x<<1|1]==0)tree[x] = tree[x<<1];
        else tree[x] = tree[x<<1]&tree[x<<1|1];
        //printf("Update %d\n",x);
    }
}
int query(int l,int r)
{
    int ans = 1<<BITMAX;
    ans--;
    l += limit;
    r += limit;
    while(l<r)
    {
        //printf("Query %d(%d)-%d(%d)\n",l,tree[l],r,tree[r]);
        if(l%2!=0)
        {
            if(tree[l]!=0)ans &= tree[l];
            l++;
        }
        if(r%2==0)
        {
            if(tree[r]!=0)ans &= tree[r];
            r--;
        }
        l/=2;
        r/=2;
    }
    if(l==r && tree[r]!=0)ans &= tree[l];
    return ans;
}
main()
{
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&l[i],&r[i],&x[i]);
        l[i]--;r[i]--;
    }
    for(i=0;i<BITMAX;i++)
    {
        for(j=0;j<n;j++)sum[j] = 0;
        for(j=0;j<m;j++)
        {
            if(x[j]&(1<<i))
            {
                sum[l[j]]++;
                sum[r[j]+1]--;
            }
        }
        for(j=0;j<n;j++)
        {
            sum[j]+=sum[j-1];
            if(sum[j]>0)a[j]|=(1<<i);
        }
    }
    //for(i=0;i<n;i++)printf("%d ",a[i]);
    //printf("\n");
    while(limit<n)limit*=2;
    //printf("limit = %d\n",limit);
    for(i=0;i<n;i++)
    {
        if(a[i]==0)QS[i]++;
        QS[i]+=QS[i-1];
        //printf("%d ",QS[i]);
    }
    //printf("\n-------------------------------------------\n");
    for(i=0;i<n;i++)
    {
        add(i,a[i]);
    }
    //for(i=1;i<limit*2;i++)printf("%d ",tree[i]);
    //printf("\n");
    for(i=0;i<m;i++)
    {
        int Q = query(l[i],r[i]);
        //printf("i = %d(%d)\n",i,Q);
        if(Q!=x[i])
        {
            if(x[i]==0 && QS[r[i]]-((l[i]-1>=0)?QS[l[i]-1]:0) > 0)continue;
            //printf("l[%d] = %d r[%d] = %d RMQ = %d\n",i,l[i],i,r[i],Q);
            printf("NO");
            return 0;
        }
    }
    printf("YES\n");
    for(i=0;i<n;i++)printf("%d ",a[i]);
}
/*
5 4
1 2 3
2 3 31
3 4 15
4 5 7



*/
