#include<bits/stdc++.h>
using namespace std;
long long ans,sum;
int main()
{
    int n,i,a;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        ans += sum*a;
        sum+=a;
    }
    printf("%d",ans);
}
