#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3+5;
const int inf = 1e9;
const int mod = 9901;
int a[MAXN];
int b[MAXN];
int Next[MAXN];
int mem[MAXN][MAXN];
vector<int>data;
int n,_max;
int f(int x,int y)
{
    //printf("%d",n);
    if(x==n && y != _max)return 0;
    else if(x==n && y==_max)return 1;
    else if(mem[x][y]==-1)
    {
        mem[x][y] = 0;
        if(Next[x])
        {
            if(y+1==Next[x])mem[x][y] = f(x+1,y+1);
            else if(y==Next[x])mem[x][y] = f(x+1,y);
            else return 0;
        }
        else
        {
            if(y+1<=_max)mem[x][y] = f(x+1,y+1);
            mem[x][y] = (mem[x][y]+f(x+1,y))%mod;
        }
        //printf("mem[%d][%d] = %d\n",x,y,mem[x][y]);
    }
    return mem[x][y];
}
main()
{
    int m,i;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    _max = n;
    data.push_back(0);
    for(i=0;i<n;i++)
    {
        while(a[i]!=0)data.push_back(i+1),a[i]--;
    }
    n = data.size();
    Next[n] = _max;
    for(i=0;i<m;i++)
    {
        scanf("%d",&b[i]);
        Next[b[i]] = data[b[i]];
    }
    /*for(i=n-1;i>0;i--)
    {
        if(!Next[i])Next[i] = Next[i+1];
    }*/
    memset(mem,-1,sizeof(mem));
    //for(i=1;i<n;i++)printf("%d ",Next[i]);
    printf("%d",f(2,1));
}
/*
3 1
2
2
2
4
*/
