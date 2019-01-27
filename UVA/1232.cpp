#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+2;
int treemin[(1<<18)+1];
int treemax[(1<<18)+1];
int treelabel[(1<<18)+1];
void update(int x)
{
    treemin[x] = min(treemin[x<<1],treemin[x<<1|1]);
    treemax[x] = max(treemax[x<<1],treemax[x<<1|1]);
}
void downdate(int x)
{
    if(treelabel[x])
    {
        treemin[x<<1] = treemax[x<<1] = treelabel[x<<1] = treelabel[x];
        treemin[x<<1|1] = treemax[x<<1|1] = treelabel[x<<1|1] = treelabel[x];
        treelabel[x] = 0;
    }
}
int ans;
void modify(int x,int l,int r,int L,int R,int val)
{
    if(l>r)return ;
    if(l!=r)downdate(x);
    if(treemin[x]>val)return ;

    if(L <= l && r <= R)
    {
        if(treemax[x]<=val)
        {
            ans+= r-l+1;
            treemax[x] = treemin[x] = treelabel[x] = val;
            return ;
        }
    }

    int mid = (l+r)>>1;
    //printf("%d %d %d %d %d %d %d\n",x,l,r,L,R,val,mid);
    if(mid >=R)modify(x<<1,l,mid,L,R,val);
    else if(mid<L)modify(x<<1|1,mid+1,r,L,R,val);
    else
    {
        modify(x<<1,l,mid,L,R,val);
        modify(x<<1|1,mid+1,r,L,R,val);
    }

    update(x);
}
main()
{
    int T,n,i,l,r,h;
    scanf("%d",&T);
    while(T--)
    {
        ans = 0;
        memset(treemax,0,sizeof(treemax));
        memset(treemin,0,sizeof(treemin));
        memset(treelabel,0,sizeof(treelabel));
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&l,&r,&h);
            r--;
            modify(1,1,MAXN,l,r,h);
        }
        printf("%d\n",ans);
    }
    scanf("%d",&T);
}
