#include<bits/stdc++.h>
using namespace std;
long long ans;
long long mem[100005];
int a[5];
int b[5];
main()
{
    int time,i,j,n;
    int t;
    bool t2;
    long long ans=0;
    int T;
    scanf("%d",&time);
    while(time--)
    {
        memset(mem,0,sizeof(mem));
        for(i=0;i<4;i++)scanf("%d",&a[i]);
        scanf("%d",&T);
        mem[0]=1;
        for(i=0;i<4;i++)for(j=a[i];j<100005;j++)mem[j]+=mem[j-a[i]];
        while(T--)
        {
            for(i=0;i<4;i++)scanf("%d",&b[i]);
            ans=0;
            scanf("%d",&n);
            for(i=(1<<4)-1;i>=0;i--)
            {
                t = n;
                t2=1;
                for(j=0;j<4;j++)
                {
                    if((i>>j)&1)t -= (b[j]+1)*a[j],t2 = !t2;
                }
                if(t>=0)
                {
                    if(t2) ans += mem[t];
                    else ans -= mem[t];
                }
            }
            printf("%lld\n",ans);
        }

    }
}
