#include<bits/stdc++.h>
using namespace std;
const int MAXN = 8e4+1;
const int mod = 1e9-1;
int tree[MAXN];
int temp[MAXN];
int a[MAXN];
void update(int x,int val)
{
    while(x<MAXN)
    {
        tree[x] = tree[x]+val;
        tree[x] = (tree[x]<0)?(tree[x]+mod)%mod:tree[x]%mod;
        //printf("Update %d: %d \n",x,tree[x][ind]);
        x += x&-x;

    }
    //printf("END");
}
int query(int x)
{
    int sum=0;
    while(x>0)
    {
        sum = sum+tree[x];
        sum = (sum<0)?(sum+mod)%mod:sum%mod;
        x -= x&-x;
    }
    return sum;
}
main()
{
    int n,m,i,k,j;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        //update(i,1,0);
        temp[i] = 1;
    }

    int t;
    int ans = 0;
    //for(i=1;i<=n;i++)printf("%d ",query(i,0));
    for(i=0;i<k;i++)
    {
        for(j=1;j<=MAXN;j++)tree[j] = 0;
        for(j=1;j<=n;j++)
        {
            t = temp[j];
            //printf("%d %d\n",query(MAXN),query(a[j]));
            temp[j] = query(MAXN)-query(a[j]);
            temp[j] = temp[j]<0 ? (temp[j]+mod)%mod : temp[j]%mod;
            update(a[j],t);
            if(i==k-1)ans = (ans+t)%mod;//printf("%d ",temp[j]);
        }
        //printf("\n");
    }
    printf("%d",ans);
}
/*

20 10
20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1


*/
