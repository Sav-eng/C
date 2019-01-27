#include<stdio.h>
#include<limits.h>
#include<algorithm>
using namespace std;
int x[1000005];
int tab[1000005];
main()
{
    int p,m,k;
    int i,j;
    int ans;
    int _x,ton,buy;
    scanf("%d%d%d",&p,&m,&k);
    for(i=1;i<=k;i++)
    {
        scanf("%d",&tab[i]);
    }
    x[0]=0;
    for(i=1;i<=m;i++)x[i]=INT_MAX/2;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=k;j++)
        {
            if(i-tab[j]>=0)
            {
                //printf("A");
                if(i<=p)x[i] = min(x[i],x[i-tab[j]]+1);
                else x[i] = min(x[i],x[i-tab[j]]+1+x[i-p]);
            }
        }
    }
    ans = INT_MAX;
    for(i=p;i<=m;i++)
    {
        printf("x[%d] = %d\n",i,x[i]);
        if(ans>x[i])
        {
            ans = x[i];
            _x= i;
        }

    }
    //printf("%d ",_x-p);
    ton = x[_x-p];
    buy = ans-ton;
    printf("%d %d",ton,buy);
}
