#include<stdio.h>
int mem[100000000];
int f(int x)
{
    if(mem[x]!=0)return mem[x];
    if(x<=0)return 0;
    if(x%2!=0 || x%3!=0 || x%4 !=0)return x;
    mem[x] = f(x/2)+f(x/3)+f(x/4);
    return mem[x];
}
main()
{
    int n;
    while(scanf("%d",&n)!='EOF')
    {
        printf("%d\n",f(n));
    }
}
