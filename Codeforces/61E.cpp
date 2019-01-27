#include<bits/stdc++.h>
#define MAXN 1000002
using namespace std;
int treeL[MAXN],treeR[MAXN];
struct node
{
    int x,ind;
};
bool cmp(node x,node y)
{
    return x.x<y.x;
}
int n;
void add(int tree[],int x,int val)
{
    while(x<=n+1)
    {
        tree[x]+=val;
        x+=x&-x;
    }
}
int query(int tree[],int x)
{
    int ans= 0;
    while(x>0)
    {
        ans += tree[x];
        x-= x&-x;
    }
    return ans;
}
node tab[MAXN];
int a[MAXN];
map<int,int>mp;
main()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        tab[i].x = a[i];
        tab[i].ind = i;
    }
    sort(tab,tab+n,cmp);
    for(i=0;i<n;i++)
    {
        if(mp[tab[i].x]==0)
        {
            mp[tab[i].x] = i+1;
            //printf("mp[%d] = %d\n",tab[i].x,i+1);
            //mp2[i+1] = tab[i].x;
        }
    }
    for(i=0;i<n;i++)
    {
        add(treeR,mp[a[i]],1);
    }
    long long ans = 0;

    int j;
    for(i=0;i<n;i++)
    {
        /*printf("\n-------------------------------------------------------\n");
        for(j=1;j<=n;j++)
        {
            printf("%d ",treeL[j]);
        }
        printf("\n-------------------------------------------------------\n");*/
        //printf("mp[%d] = %d\n",a[i],mp[a[i]]);
        add(treeR,mp[a[i]],-1);
        //printf("Q(L,%d) = %d Q(R,%d) = %d\n",mp[a[i]],query(treeL,n)-query(treeL,mp[a[i]]),mp[a[i]],query(treeR,mp[a[i]]-1));
        ans += (long long)(query(treeL,n)-query(treeL,mp[a[i]]))*(query(treeR,mp[a[i]]-1));
        add(treeL,mp[a[i]],1);
    }
    printf("%I64d",ans);
}
/*
3
1000000003 1000000002 1000000001


*/
