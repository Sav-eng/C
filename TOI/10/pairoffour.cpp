#include<bits/stdc++.h>
using namespace std;
int mem[1001][1001];
int mem2[1001][1001];
char x[1001];
int f(int l,int r)
{
    if(l>=r)return 0;
    else if(!mem[l][r])
    {
        mem[l][r] = max(f(l+1,r),f(l,r-1));
        if(x[l]==x[r])mem[l][r] = max(mem[l][r],f(l+1,r-1)+1);
        //printf("mem[%d][%d] = %d\n",l,r,mem[l][r]);
    }
    return mem[l][r];
}
int n;
int f2(int x,int y)
{
    if(x==n)return 0;
    else if(y==n && x!=n)return -1e9;
    else if(!mem2[x][y])
    {
        mem2[x][y] = max(mem[x][y]+f2(y+1,y+1),f2(x,y+1));
        //printf("mem2[%d][%d] = %d\n",x,y,mem2[x][y]);
    }
    return mem2[x][y];
}
main()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf(" %c",&x[i]);
    f(0,n-1);
    printf("%d",f2(0,0));
}
