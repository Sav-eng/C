#include<bits/stdc++.h>
using namespace std;
int mem[101][100001];
int n;
int a[101];
int f(int x,int y)
{
    if(x==n && y>=50000)return y-50000;
    else if(x==n)return 50000-y;
    else if(mem[x][y]==-1)mem[x][y] = min(f(x+1,y+a[x]),f(x+1,y-a[x]));
    return mem[x][y];
}
main()
{
    int time,i;
    scanf("%d",&time);
    while(time--)
    {
        memset(mem,-1,sizeof(mem));
        scanf("%d",&n);
        for(i=0;i<n;i++)scanf("%d",&a[i]);
        printf("%d\n",f(0,50000));
    }
}
