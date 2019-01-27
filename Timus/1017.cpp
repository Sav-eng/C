#include<stdio.h>
#include<string.h>
long long tab[550][550];
int n;
long long f(int x,int y)
{
    int i;
    if(x==0)return 1;
    if(tab[x][y]!=-1)return tab[x][y];
    tab[x][y] = 0;
    for(i=y+1;i<=x;i++)
    {
        tab[x][y] += f(x-i,i);
    }
    //printf("tab[%d][%d] = %d\n",x,y,tab[x][y]);
    return tab[x][y];
}
main()
{
    scanf("%d",&n);
    memset(tab,-1,sizeof(tab));
    printf("%lld",f(n,0)-1);
}
