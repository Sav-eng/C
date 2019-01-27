#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;
map<long long,int>check;
long long tab[2000000];
char a[2000000];
main()
{
    int n,k,i,cnt;
    int ans = 0;
    scanf("%d%d",&n,&k);
    scanf("%s",&a);
    for(i=2;i<=n+1;i++)
    {
        if(a[i-1]=='R')tab[i] = tab[i-1]+k;
        else tab[i] = tab[i-1]-1;
    }
    //for(i=0;i<=n;i++)printf("%d ",tab[i]);
    tab[1]=0;
    for(i=1;i<=n+1;i++)
    {
        if(check[tab[i]] == 0)
        {
            check[tab[i]] = i;
        }
        else
        {
            ans = max(ans,i-check[tab[i]]);
        }
    }
    printf("%d",ans);
}
/*

3 2
OOR


*/
