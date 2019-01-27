#include<stdio.h>
#include<algorithm>
#include<limits.h>
using namespace std;
int n;
int mem[2005][2005];
int a[2005];
int f(int x,int c)
{
    if(c<0)return INT_MIN/2;
    if(c>2000)return INT_MIN/2;
    if(x==-1 && c!= 0)return INT_MIN/2;
    if(x==-1 && c==0)return 0;
    if(mem[x][c]!=0)return mem[x][c];
    if(c==0)mem[x][c] = f(x-1,0);
    mem[x][c] = max(max(mem[x][c],f(x-1,c+2)-a[x]),a[x] + f(x-1,c-1));
    //printf("mem[%d][%d] = %d\n",x,c,mem[x][c]);
    return mem[x][c];
}
main()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("%d",f(n-1,0));
}
