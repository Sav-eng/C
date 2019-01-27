#include<stdio.h>
#include<math.h>
#include<map>
using namespace std;
map<long long,long long>a;
long long n,k,i,cnt=0;
bool check=0;
main()
{
    scanf("%lld%lld",&n,&k);
    if(k>n)
    {
        printf("-1");
        return 0;
    }
    //printf("%lf",sqrt(12));
    for(i=1;i<=(int)sqrt(n);i++)
    {
        if(n%i==0)
        {
            a[cnt++] = i;
        }
        if(cnt==k)
        {
            printf("%lld",i);
            return 0;
        }
        if(i*i==n)check=1;
    }
    if(check)i = 2*cnt-k-1;
    else i = 2*cnt-k;
    //i = k-cnt-1;
    //printf("cnt= %lld ",cnt);
    if(a[i]!=0)
    {
        printf("%lld",n/a[i]);
        return 0;
    }
    else printf("-1");
}
/*

4 3

*/
