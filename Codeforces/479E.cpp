#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long mem[5001];
long long Qs[5001];
main()
{
    int n,s,e,k,i,j;
    scanf("%d%d%d%d",&n,&s,&e,&k);
    if(s>e)
    {
        s = n+1-s;
        e = n+1-e;
    }
    for(i=1;i<=n;i++)mem[i] = 1;
    for(i=0;i<k;i++)
    {
        Qs[1] = mem[1];
        for(j=2;j<e;j++)
        {
            Qs[j] = ((long long)Qs[j-1]+mem[j]+mod)%mod;
            //printf("%d ",Qs[j]);
        }
        for(j=1;j<e;j++)
        {
            mem[j] = 0;
        }
        for(j=1;j<e;j++)
        {
            mem[j] = ((long long)Qs[e-1]-Qs[max(0,2*j-e)]-Qs[j]+Qs[j-1]+mod)%mod;
            //printf("mem[%d][%d] = %d\n",i,j,mem[j]);
        }
        //printf("\n");
    }
    //int ans=0;
    //for(i=0;i<e;i++)ans = (ans+mem[i]+mod)%mod;
    printf("%I64d",mem[s]>=0?mem[s]:mem[s]+mod);
}
