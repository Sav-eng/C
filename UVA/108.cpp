#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
int sum[101][101];
int a;
main()
{
    int n,i,j,k,_sum,ans,_min=-inf;
    bool check=0;
    while(scanf("%d",&n)!=EOF)
    {
        check=0;
        memset(sum,0,sizeof(sum));
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&a);
                if(a<0)_min = max(a,_min);
                sum[i][j] = a+sum[i][j-1];
                //printf("%d ",sum[i][j]);
            }
            //printf("\n");
        }
        /*for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                printf("%d ",sum[i][j]);
            }
            printf("\n");
        }*/
        ans = 0;
        for(i=0;i<n;i++)
        {
            for(j=i;j<n;j++)
            {
                _sum =0;
                for(k=0;k<n;k++)
                {
                    _sum+=sum[k][j]-sum[k][i-1];
                    if(_sum<0)_sum=0;
                    if(ans<_sum)
                    {
                        ans = _sum;
                        check=1;
                    }
                }
            }
        }
        if(check)printf("%d\n",ans);
        else printf("%d\n",_min);
    }

}
