#include<stdio.h>
int tab[30005];
main()
{
    int n,m,a,b,i,check=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<n-1;i++)
    {
        scanf("%d%d",&a,&b);
        tab[a]++;
        tab[b]++;
    }
    for(i=0;i<=n;i++)
    {
        if(tab[i]==1)check++;
    }
    printf("%d",(check+1)/2);
}
