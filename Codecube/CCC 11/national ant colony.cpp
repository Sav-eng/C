#include<bits/stdc++.h>
#define inf 2e9
using namespace std;
int a[80001];
int head[80001];
int x[80001];
int y[80001];
int z[80001];
int rhead[80001];
int findhead(int x)
{
    if(x==head[x])return x;
    return head[x] = findhead(head[x]);
}
main()
{
    int l = inf;
    int r = 0;
    int n,m,k;
    int i;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&x[i],&y[i],&z[i]);
        l = min(l,z[i]);
        r = max(r,z[i]);
    }
    int ans = 0;
    while(l<=r)
    {
        int mid = (l+r)/2;
        bool check = 0;
        for(i=1;i<=n;i++)head[i] = i,rhead[i]=0;
        for(i=0;i<m;i++)
        {
            if(z[i]>mid)head[findhead(x[i])] = findhead(head[y[i]]);
        }
        //for(i=1;i<=n;i++)printf("%d ",head[i]);
        for(i=1;i<=n;i++)
        {
            if(rhead[a[i]]==0)rhead[a[i]] = head[findhead(i)];
            else
            {
                if(rhead[a[i]]!=head[findhead(i)])check = 1;
            }
            //printf("%d ",rhead[i]);
        }
        //printf("\n");
        if(!check)
        {
            ans = mid;
            l = mid+1;
        }
        else
        {
            r = mid-1;
        }
        //printf("l = %d r = %d mid = %d\n",l,r,mid);
    }
    int ans2 = 0;
    for(i=0;i<m;i++)
    {
        ans2 += (z[i]>ans)?0:1;
    }
    printf("%d",ans2);
}
