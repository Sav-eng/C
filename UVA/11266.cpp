#include<bits/stdc++.h>
#define mod 200003
#define shift 100000
using namespace std;
int mem[15][200006];
int a[11];
int b[11];
main()
{
    int n,m,time,i,j,l,r,sum=0;
    scanf("%d",&time);
    while(time--)
    {
        memset(mem,0,sizeof(mem));
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)scanf("%d%d",&a[i],&b[i]);
        for(i=a[0];i<=b[0];i++) mem[0][i+shift]=1;
        for(i=1;i<n;i++)
        {
            l = -b[i]; r = -a[i];
            sum=0;
            for(j=l;j<=r;j++)if(j>=0 && j<=200005)sum=(sum+mem[i-1][j]+mod)%mod;
            for(j=0;j<=200005;j++)
            {
                mem[i][j] = sum;
                //if(sum!=0)printf("mem[%d][%d] = %d\n",i,j-shift,mem[i][j]);
                if(l>=0 && l<=200005)sum = (sum-mem[i-1][l]+mod)%mod;
                if(r+1>=0 && r+1 <=200005)sum = (sum+mem[i-1][r+1]+mod)%mod;
                l++;r++;
            }
        }
        printf("%d\n",(mem[n-1][m+shift]+mod)%mod);
    }
}
/*

1
3 10
-1 3
2 4
6 7
*/
