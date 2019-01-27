#include<bits/stdc++.h>
using namespace std;
int ans[3001];
main()
{
    int T = 10;
    int n,k,i,sum;
    while(T--)
    {
        memset(ans,0,sizeof(ans));
        scanf("%d%d",&n,&k);
        sum = ((n*(n+1)/2)-1);
        for(i=n;i>1;i--)
        {
            if(sum-2*i>=k-1 && sum-2*i != k+1)
            {
                ans[i] = 1;
                sum-=2*i;
            }
        }
        if(sum==k-1)
        {
            printf("1");
            for(i=2;i<=n;i++)
            {
                if(ans[i])printf("%d",-i);
                else printf("+%d",i);
            }
        }
        else printf("Impossible");
        printf("\n");
    }

}
