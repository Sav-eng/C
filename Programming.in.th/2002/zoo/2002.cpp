#include<bits/stdc++.h>
#define MAXN 50010
#define inf 1e9
using namespace std;
int mem[MAXN][32];
int like[MAXN][10];
int unlike[MAXN][10];
vector<int>from[MAXN];
int n;
int a[MAXN];
int b[MAXN];
int vis[MAXN];
int N;
int Fbit;
int f(int x,int bit)
{
    if(x>n)return 0;
    else if(mem[x][bit]==-1)
    {
        mem[x][bit]= 0;
        int i,j;
        for(i=0;i<from[x].size();i++)
        {
            int ord = from[x][i];
            int t;
            bool check = 0;
            for(j=0;j<a[ord];j++)
            {
                if(unlike[ord][j]<=N)
                {
                    t = 4-x+unlike[ord][j];
                    if((bit&(1<<t))!=0)check=1;
                }
                else
                {
                    t = unlike[ord][j]-N-1;
                    if((Fbit&(1<<t))!=0)check=1;
                }
                //if(x==6)printf("%d & %d %d (%d)\n",bit,1<<t,check,bit&(1<<t));
            }
            for(j=0;j<b[ord];j++)
            {
                if(like[ord][j]<=N)
                {
                    t = 4-x+like[ord][j];
                    if((bit&(1<<t))==0)check=1;
                }
                else
                {
                    t = like[ord][j]-N-1;
                    if((Fbit&(1<<t))==0)check=1;
                }
                //if(x==6)printf("%d & %d %d (%d)\n",bit,1<<t,check,bit&(1<<t));
            }
            mem[x][bit] += (check)?1:0;
            //printf("mem[%d][%d][%d] = %d\n",x,bit,Fbit,mem[x][bit][Fbit]);
            //if(vis[x]<from[x].size() && mem[x][bit]>0)printf("mem[%d][%d] = %d\n",x,bit,mem[x][bit]),vis[x];
        }
        mem[x][bit] += max(f(x+1,bit>>1),f(x+1,((bit>>1)|(1<<4))));
        /*if(x==5)
        {
            int t = bit;
            printf("%d ",t);
            for(i=4;i>=0;i--)
            {
                if((t&(1<<i))>=1)printf("1");
                else printf("0");
            }
            printf("\n");
        }*/
        //printf("mem[%d][%d] = %d\n",x,bit,mem[x][bit]);
    }
    return mem[x][bit];
}
main()
{
    //freopen("2.in","r",stdin);
    //freopen("out.txt","w",stdout);
    int m,i,j,s;
    scanf("%d%d",&n,&m);
    memset(mem,-1,sizeof(mem));
    int b1,b2,b3,b4,b5;
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
    N = n;
    n+=4;
    int ans = 0;
    for(Fbit=0;Fbit<32;Fbit++)
    {
        memset(mem,-1,sizeof(mem));
        ans = max(ans,f(5,Fbit));
        //printf("Fbit = %d ans = %d\n",Fbit,ans);
    }
    printf("%d\n",ans);
    //printf("%d",mem[2][1<<4]);
}
/*
14 5
2 1 2 4 2 6
3 1 1 6 4
6 1 2 9 6 8
8 1 1 9 12
12 3 0 12 13 2

10 12
2 0 1 2
4 2 2 5 7 4 6
4 0 1 6
4 2 2 5 8 6 7
4 1 2 4 7 8
5 3 0 5 6 7
7 1 3 8 7 9 10
8 2 3 9 1 8 10 2
8 3 0 8 10 1
8 3 1 8 9 10 1
9 1 3 9 1 2 3
10 0 3 1 3 4

10 60
1 3 0 2 3 4
1 0 1 2
1 1 3 1 2 4 5
1 0 3 3 4 5
1 1 1 3 5
1 1 1 3 2
1 1 1 5 1
2 1 4 6 2 3 4 5
2 1 1 4 3
2 2 2 3 5 2 6
2 2 1 3 4 2
2 1 2 2 5 6
2 2 3 3 5 2 4 6
2 2 1 4 5 6
3 1 1 4 7
3 1 2 3 4 5
3 2 2 3 7 4 6
4 2 1 4 6 8
4 1 2 6 5 7
4 1 4 5 4 6 7 8
4 3 0 4 5 8
4 2 1 5 8 4
5 1 1 6 9
5 2 1 5 8 9
5 3 1 5 6 8 9
5 1 3 8 5 7 9
5 3 1 5 6 8 9
5 1 2 5 6 9
5 1 2 8 7 9
5 2 2 5 8 6 7
5 3 1 5 7 8 6
5 1 1 7 9
6 1 2 10 6 9
6 2 2 6 9 7 10
6 3 1 6 7 8 10
6 2 1 7 9 10
6 1 2 8 7 10
6 2 1 6 9 10
6 2 2 6 10 7 8
7 1 2 10 7 8
7 2 2 9 1 7 8
7 0 3 8 9 10
7 3 1 8 10 1 9
7 2 2 7 8 9 1
7 2 2 8 9 10 1
7 2 2 8 9 7 10
8 3 0 9 10 1
8 1 0 1
8 3 1 9 1 2 8
8 1 3 10 8 9 2
8 2 1 10 1 2
9 1 2 3 9 2
9 0 3 10 1 3
9 1 3 2 9 10 1
10 1 2 4 10 3
10 1 0 10
10 2 2 10 2 1 3
10 0 3 10 3 4
10 3 0 10 1 4
10 2 2 1 3 10 4


*/
