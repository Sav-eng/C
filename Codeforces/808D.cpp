#include<bits/stdc++.h>
#define MAXN 100001
using namespace std;
multiset<long long>S;
multiset<long long>S2;
long long sum[MAXN];
long long a[MAXN];
main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%I64d",&a[i]);
        sum[i] = (long long)sum[i-1]+a[i];
        S.insert(a[i]);
    }
    for(i=0;i<n;i++)
    {
        long long t = (long long)(sum[n-1]-(2*sum[i]));
        S.erase(S.find(a[i]));
        S2.insert(a[i]);
        if(!t)
        {
            printf("YES");
            return 0;
        }
        if(t%2==0)
        {
            if(t>0)
            {
                if(S.find(t/2)!=S.end())
                {
                    //printf("%d ",i);
                    printf("YES");
                    return 0;
                }
            }
            else
            {
                t*=-1;
                if(S2.find(t/2)!=S2.end())
                {
                    //printf("%d ",i);
                    printf("YES");
                    return 0;
                }
            }
        }

    }
    printf("NO");
}
/*

5
1 2 3 4 6

*/
