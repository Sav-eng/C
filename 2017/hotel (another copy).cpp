#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
int n;
int mem[1000001];
int coin[] = {1,2,5,15};
int pay[] = {500,800,1500,3000};
int f(int x)
{
    int i;
    if(x>=n)return 0;
    else if(!mem[x])
    {
        mem[x] = inf;
        for(i=0;i<4;i++)
        {
            mem[x] = min(mem[x],f(x+coin[i])+pay[i]);
        }
    }
    return mem[x];
}
main()
{
    scanf("%d",&n);
    printf("%d",f(0));
}
