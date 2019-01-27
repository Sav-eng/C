#include<stdio.h>
#include<map>
#include<string.h>
using namespace std;
map<int,int> a;
int x;
int point[1000000];
main()
{
    int n,c,k,i,p;
    scanf("%d%d%d",&n,&c,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&x,&p);
        a[x]++;
        if(a[x]<=k) point[p]++;
    }
    for(i=0;i<c;i++)
    {
        printf("%d\n",point[i+1]);
    }
}
