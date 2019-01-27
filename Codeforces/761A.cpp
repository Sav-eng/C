#include<stdio.h>
int abs(int x)
{
    if(x<0)return -x;
    return x;
}
int x,y;
main()
{

    scanf("%d%d",&x,&y);
    if(abs(x-y)<=1&& (x || y))printf("YES");
    else printf("NO");
}
