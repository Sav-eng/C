#include<bits/stdc++.h>
using namespace std;
main()
{
    freopen("j1.in","r",stdin);
    freopen("j1.out","w",stdout);
    int T,n,i;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        printf("%d\n",n-1);
        for(i=0;i<n-1;i++)printf("0 %d\n",i);
    }
}
