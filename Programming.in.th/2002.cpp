#include<bits/stdc++.h>
#define MAXN 50010
#define inf 1e9
using namespace std;
int mem[MAXN][40];
int like[MAXN][10];
int unlike[MAXN][10];
vector<int>from[MAXN];
int n;
int a[MAXN];
int b[MAXN];
int f(int x,int bit)
{
    if(x==n+1)return 0;
    else if(mem[x][bit]==-1)
    {
        mem[x][bit] = 0;
        int i,j;
        //int X = (n-x<4)?x-4:x;
        //printf("X = %d\n",X);
        //if(X<0)return 0;
        //printf("X = %d x = %d\n",X,x);
        for(i=0;i<from[x].size();i++)
        {
            //printf("a");
            int ord = from[x][i];
            int t;
            bool check = 0;
            for(j=0;j<a[ord];j++)
            {
                t = 4-x+unlike[ord][j];
                if((bit&(1<<t))!=0)check=1;
                //printf("%d & %d %d (%d)\n",bit,1<<t,check,bit&(1<<t));
            }
            for(j=0;j<b[ord];j++)
            {
                t = 4-x+like[ord][j];
                if(bit&(1<<t)==0)check=1;
                //printf("%d & %d %d (%d)\n",bit,1<<t,check,bit&(1<<t));
            }
            mem[x][bit] += (check)?1:0;
            //printf("mem[%d][%d] = %d\n",x,bit,mem[x][bit]);
        }
        mem[x][bit] += max(f(x+1,bit>>1),f(x+1,(bit>>1)|(1<<4)));
        //printf("mem[%d][%d] = %d\n",x,bit,mem[x][bit]);
    }
    return mem[x][bit];
}
main()
{
    int m,i,j,s;
    scanf("%d%d",&n,&m);
    memset(mem,-1,sizeof(mem));
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&s,&a[i],&b[i]);
        from[s+4].push_back(i);
        for(j=0;j<a[i];j++)
        {
            scanf("%d",&unlike[i][j]);// n = 5
            if(s-unlike[i][j]>0)unlike[i][j]+=n;
        }
        for(j=0;j<b[i];j++)
        {
            scanf("%d",&like[i][j]);
            if(s-like[i][j]>0)like[i][j]+=n;
        }
    }
    n+=4;
    printf("%d",max(f(1,0),f(1,1<<4)));
}
/*
14 5
2 1 2 4 2 6
3 1 1 6 4
6 1 2 9 6 8
8 1 1 9 12
12 3 0 12 13 2

14 2
1 1 1 1 2
2 1 0 2

3 2
1 1 0 1
1 0 1 1
*/
