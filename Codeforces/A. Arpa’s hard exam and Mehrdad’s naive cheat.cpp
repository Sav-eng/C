#include<stdio.h>
main()
{
    int ans = 1,i,n;
    scanf("%d",&n);
    if(n==0)
    {
        printf("1");
        return 0;
    }
    if(n%4==0)printf("6");
    if(n%4==1)printf("8");
    if(n%4==2)printf("4");
    if(n%4==3)printf("2");
}
