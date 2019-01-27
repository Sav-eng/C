#include<stdio.h>
#include<algorithm>
#include<limits.h>
using namespace std;
main()
{
    int n,x,_max,_min,i;
    _max = INT_MIN;
    _min = INT_MAX;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        _min =min(_min,x);
        _max =max(_max,x);
    }
    printf("%d\n%d",_max,_min);
}
