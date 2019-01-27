#include<bits/stdc++.h>
using namespace std;
long long a[100001];
main()
{
    long long n,i,m,x,y,h1,L;
    scanf("%I64dd",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%I64dd",&a[i]);
    }
    scanf("%I64d",&m);
    h1 = 0;
    L = 0;
    for(i=0;i<m;i++)
    {
        scanf("%I64d%I64d",&x,&y);
        L = max(L+h1,a[x]);
        h1 = y;
        printf("%I64d\n",L);
        //printf("i = %d\n",i);
    }
}
