#include<stdio.h>
#include<algorithm>
using namespace std;
int n,m,a[1000]={40,1,3,4,6,1,4,5,6,10},val[1000]={1,2,4,6,10,6,19,57,41,31};
int mem[100][100];
int trace[100][100];
int f(int x,int w)
{
    if(w>m)return -500000;
    if(x>=n)return 0;
    mem[x][w] = max(f(x+1,w),val[x] + f(x+1,w+a[x]));
    if(f(x+1,w)>val[x] + f(x+1,w+a[x]))trace[x][w]=0;
    else trace[x][w]=1;
    return mem[x][w];
}
main()
{
    n=10;
    m = 20;
    printf("%d",f(0,0));
    int x=0,y=0;
    printf("\n");
    while(x<10 && y <f(0,0))
    {
        if(trace[x][y] == 1)
        {
            printf("%d ",x);
            y += a[x];
            x++;
        }
        else x++;
    }
}
