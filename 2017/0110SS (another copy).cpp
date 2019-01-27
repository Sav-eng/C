#include<bits/stdc++.h>
using namespace std;
int n;
long long mem[71][2];
long long f(int x,int y)
{
    if(x==n)return 1;
    else if(!mem[x][y])
    {
        if(y==1)
        {
            mem[x][y] = f(x+1,0)+f(x+1,1);
        }
        else mem[x][y] = f(x+1,1);
    }
    return mem[x][y];
}
main()
{
    scanf("%d",&n);
    printf("%lld",f(0,1));
}

