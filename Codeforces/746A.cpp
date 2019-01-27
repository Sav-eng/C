#include<stdio.h>
main()
{
    int a,b,c,n=0;
    scanf("%d%d%d",&a,&b,&c);
    while(a>= 1 && b>= 2 &&c >= 4)
    {
        n++;
        a--;
        b-=2;
        c-=4;
    }
    printf("%d",7*n);
}
