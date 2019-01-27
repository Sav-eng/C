#include<stdio.h>
#include<math.h>
int func(int x)
{
    float ans;
    ans = pow(x,2)+sqrt(x)/3;
    printf("F(x) = %d So Ans =%f\n",x,ans);
}
main()
{
    int i;
    for(i=0;i<=20;i++)
        func(i);
}
