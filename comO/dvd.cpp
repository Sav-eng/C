#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+2;
int limit;
int treemin[MAXN*4];
int treemax[MAXN*4];
void updatemin(int x,int val)
{
    x += limit;
    treemin[x] = val;
    while(x>0)
    {
        x >>=1;
        treemin[x] = min(treemin[x<<1],treemin[x<<1|1]);
    }
}
void updatemax(int x,int val)
{
    x += limit;
    treemax[x] = val;
    //printf("Update : tree2[%d] = %d\n",x,tree2[x]);
    while(x>0)
    {
        x>>=1;
        treemax[x] = max(treemax[x<<1],treemax[x<<1|1]);
    }
}
int querymin(int l,int r)
{
    l+=limit;
    r+= limit;
    int ans = MAXN;
    while(l<r)
    {
        //printf("%d %d\n",l,r);
        if(l%2!=0)ans = min(ans,treemin[l++]);
        if(r%2==0)ans = min(ans,treemin[r--]);
        l>>=1,r>>=1;
    }
    if(l==r)ans = min(ans,treemin[l]);
    return ans;
}
int querymax(int l,int r)
{
    int ans = 0;
    l+=limit;
    r += limit;
    while(l<r)
    {
        if(l%2!=0)ans = max(ans,treemax[l++]);
        if(r%2==0)ans = max(ans,treemax[r--]);
        l>>=1,r>>=1;
    }
    if(l==r)ans = max(ans,treemax[l]);
    return ans;
}
main()
{
    int n,T,op,x,y,i;
    scanf("%d%d",&n,&T);
    limit = 1;
    while(limit<n)limit<<=1;
    //printf("limit = %d\n",limit);
    for(i=0;i<=limit;i++)
    {
        updatemin(i,MAXN);
        updatemax(i,0);
    }
    for(i=0;i<n;i++)
    {
        updatemin(i,i);
        updatemax(i,i);
    }
    //for(i=1;i<=2*limit;i++)printf("%d ",treemin[i]);
    //printf("\n");
    while(T--)
    {
        scanf("%d",&op);
        if(!op)
        {
            scanf("%d%d",&x,&y);
            int t = treemin[x+limit];
            int t2 = treemin[y+limit];
            updatemin(x,t2);
            updatemin(y,t);
            updatemax(x,t2);
            updatemax(y,t);
        }
        else
        {
            scanf("%d%d",&x,&y);
            int _min = querymin(x,y);
            int _max = querymax(x,y);
            //printf("_min = %d _max = %d\n",_min,_max);
            if(_min == x && _max==y)printf("YES\n");
            else printf("NO\n");
        }
    }
}
