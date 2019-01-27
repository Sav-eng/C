#include<bits/stdc++.h>
using namespace std;
int sum[501][501];
main()
{
    int t=2;
    int n,m,time,b,a,i,j,k,in,out,ans=0;
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&time);
        memset(sum,0,sizeof(sum));
        for(i=0;i<time;i++)
        {
            scanf("%d%d",&a,&b);
            sum[a][b] = 1;
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                sum[i][j] = sum[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
                //printf("%d ",sum[i][j]);
            }
            //printf("\n");
        }
        ans = 0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                for(k=1;k<=min(n-i,m-j);k++)
                {
                    in = sum[i+k-2][j+k-2]-sum[i+k-2][j]-sum[i][j+k-2]+sum[i][j];
                    out = sum[i+k-1][j+k-1]-sum[i-1][j+k-1]-sum[i+k-1][j-1]+sum[i-1][j-1];
                    if(out-in==0)
                    {
                        //printf("%d %d %d out=%d in=%d\n",i,j,k,out,in);
                        ans = max(ans,k);
                    }
                }
            }
        }
        printf("%d\n",ans);
    }


}

