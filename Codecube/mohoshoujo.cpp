#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
int a[100001];
int mem[1001];
int ans[100001];
main()
{
    int n,k,i,t,range,j;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++)
    {
        mem[a[i]]=i;
        t=  inf;
        if(i-k+1>=0)range = i-k+1;
        else range = 0;
        for(j=1000;j>=0;j--)
        {
            if(mem[j]>=range)
            {
                //printf("ans[%d] = %d ",range-1,ans[range-1]);
                if(t>j+ans[range-1]) t = j+ans[range-1];
                range = mem[j]+1;
                //printf("%d %d\n",j,t);
            }
        }
        ans[i] = t;
    }
    //for(i=0;i<n;i++)printf("%d ",ans[i]);
    printf("%d",ans[n]);
}
/*

8 5
1 4 1 3 4 7 2 2


*/
