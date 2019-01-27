#include<stdio.h>
main()
{
    int n,m,k;
    char x[150000];
    scanf("%d%d%d ",&n,&m,&k);
    gets(x);
    if(x[m-1]==x[k-1])printf("0");
    else printf("1");

}
