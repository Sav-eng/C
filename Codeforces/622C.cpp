#include<bits/stdc++.h>
using namespace std;
int a[200001];
int b[200001];
main()
{
    int n,m,i,l,r,x;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==a[i-1])b[i] = b[i-1];
        else b[i] = i-1;
    }
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&l,&r,&x);
        if(a[r]!=x)printf("%d\n",r);
        else if(b[r]>=l && b[r])printf("%d\n",b[r]);
        else printf("-1\n");
    }
}
