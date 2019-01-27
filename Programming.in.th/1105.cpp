#include<stdio.h>
#include<algorithm>
using namespace std;
int mem[2000000],a[2000000];
main()
{
    int n,k,i,cm=0;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        mem[a[i]]=1;
        cm = max(cm,a[i]);
    }
    int check = 0;
    i=cm;
    while(check<k)
    {
        if(mem[i]==1)check++;
        i--;
    }
    printf("%d",i+1);
}
