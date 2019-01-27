#include<stdio.h>
#include<algorithm>
using namespace std;
main()
{
    int n,m,k,sum;
    scanf("%d%d%d",&n,&m,&k);
    sum = max(m,n);
    while(sum%n!=0 || sum%m!=0)
    {
        sum++;
    }
    printf("%d",k/sum);
}
