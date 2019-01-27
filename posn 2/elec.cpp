#include<stdio.h>
#include<algorithm>
#include<limits.h>
#include<string.h>
using namespace std;
int mem[10000];
int n,k;
int a[10000];
int f(int x)
{
   // printf("a");
   // printf("%d",mem[x]);
    if(x>=n)return 0;
    //if(mem[x]!=INT_MAX/2)return mem[x];
    int i;
    //printf("a");
    for(i=1;i<=k;i++)
    {
        //printf("%d\n",i);
        if(x+i<n)
        {
            //printf("%d %d\n",a[i-1+x]+f(x+i),mem[x]);
            mem[x] = min(mem[x],a[i-1+x]+f(x+i));
        }
    }
    return mem[x];
}
main()
{
    int i;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        mem[i] = INT_MAX/2;
    }
    //for(i=0;i<n;i++)printf("%d",mem[i]);
    printf("%d",f(0));
}
