#include<bits/stdc++.h>
using namespace std;
int a[50001];
main()
{
    int n,i,m,x,ans1,ans2;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    sort(&a[0],&a[n]);
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        scanf("%d",&x);
        int *low,*up;
        low = lower_bound(&a[0],&a[n],x);
        up = upper_bound(&a[0],&a[n],x);
        ans1 = low-&a[0];
        ans2 = up-&a[0];
        if(ans1==0)printf("X %d\n",a[ans2]);
        else if(ans2==n)printf("%d X\n",a[ans1-1]);
        else printf("%d %d\n",a[ans1-1],a[ans2]);
    }
}
