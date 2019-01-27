#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int Qs[1000001];
main()
{
    int T,n,i;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            a[i] *=-1;
        }
        sort(a,a+n);
        memset(Qs,0,sizeof(Qs));
        for(i=0;i<n;i++)
        {
            a[i] *= -1;
            Qs[i] += Qs[i-1];
            int t = Qs[i];
            a[i] -= t;
            if(a[i]<0)a[i]*=-1;
            Qs[i+1]+=1;
            Qs[i+1+a[i]] -= 1;
        }
        if(i==n && a[n-1]==0)printf("Yes\n");
        else printf("No\n");
    }
}
