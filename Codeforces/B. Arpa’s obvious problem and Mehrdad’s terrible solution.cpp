#include<stdio.h>
int cross[50000];
main()
{
    int check;
    check = 1;
    while(check<=1e5)
    {
        check*=2;
        cross[check] = 1;
    }
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
