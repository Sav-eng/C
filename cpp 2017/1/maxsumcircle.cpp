#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000001];
int kadane(int a[])
{
    int i,sum=0,maxsum=-1e9;
    for(i=0;i<n;i++)
    {
        sum += a[i];
        sum = (sum<0)?0:sum;
        maxsum = max(maxsum,sum);
    }
    return maxsum;
}
int main()
{
    //freopen("10.in","r",stdin);
    //freopen("10.out","w",stdout);
    int i,_maxcircu = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int max_kadane = kadane(a);
    for(i=0;i<n;i++)
    {
        _maxcircu += a[i];
        a[i] *= -1;
    }
    printf("%d",max(max_kadane,kadane(a)+_maxcircu));
}
