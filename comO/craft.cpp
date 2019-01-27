#include<bits/stdc++.h>
using namespace std;
int a[30];
vector<long long>have[3];
main()
{
    int n,m,i,j;
    bool flag=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<n-1;i++)scanf("%d",&a[i]);
    have[flag].push_back(m);
    for(i=n-2;i>=0;i--)
    {
        for(j=0;j<have[flag].size();j++)
        {
            int t = 2*have[flag][j]+1;
            t-=a[i];
            if(t<2)
            {
                printf("-1");
                return 0;
            }
            if(t%2==0)
            {
                have[!flag].push_back(t/2);
                have[!flag].push_back(t/2);
            }
            else
            {
                have[!flag].push_back(t/2);
                have[!flag].push_back(t/2+1);
            }

        }
        have[flag].clear();
        flag = !flag;
    }
    long long  ans = 0;
    for(i=0;i<have[flag].size();i++)
    {
        ans += have[flag][i];
    }
    printf("%lld",ans);

}
