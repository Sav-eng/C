#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+2;
const int inf = 1e9;
int L[MAXN];
int R[MAXN];
int ANS[MAXN];
int par[MAXN][22];
int s,a,b,X;
int dir(void)
{
    int res = ((s & 8) >> 3);
    s = (s * a + b) % 40507;
    return res;
}
int ans;
int level[MAXN];
void dfs(int H,int now)
{
    ANS[H] = now;
    if(L[now]!= -1 && R[now]!=-1)
    {
        int t = dir();
        if(t%2==0)dfs(H+1,L[now]);
        else dfs(H+1,R[now]);
    }
    else if(L[now]==-1 && R[now]!=-1)dfs(H+1,R[now]);
    else if(L[now]!=-1 && R[now]==-1)dfs(H+1,L[now]);
    else
    {
        ANS[H] = now;
        return ;
    }
}
void dfs2(int H,int now)
{
    level[now] = H;
    if(L[now]!= -1 && R[now]!=-1)
    {
        dfs2(H+1,L[now]);
        dfs2(H+1,R[now]);
    }
    else if((L[now]==-1 && R[now]!=-1) || (L[now]!=-1 && R[now]==-1))
    {
        if(L[now]!=-1)dfs2(H+1,L[now]),par[now][0] = L[now];
        if(R[now]!=-1)dfs2(H+1,R[now]),par[now][0] = R[now];
        for(int i=1;i<20;i++)par[now][i] = par[par[now][i-1]][i-1];
    }
    else return ;
}
main()
{
    int n,T,i;
    scanf("%d%d",&n,&T);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&L[i],&R[i]);
    }
    int now,H;
    int S,A,B,j;
    int CHECK = 0;
    dfs2(0,0);
    level[0] = inf;
    while(T--)
    {
        scanf("%d%d%d%d",&X,&s,&a,&b);
        if(S==s && A==a && B==b)
        {
            if(!CHECK)
            {
                dfs(0,0);
                CHECK=1;
                for(i=0;i<=MAXN;i++)if(ANS[i]==0)ANS[i] = ANS[i-1];
            }
            printf("%d\n",ANS[X]);
        }
        else
        {
            S=s;A=a;B=b;
            now = 0;H = 0;
            while(H!=X)
            {
                if(L[now]!=-1 && R[now]!=-1)
                {
                    int t = dir();
                    if(!t)H++,now = L[now];
                    else H++,now = R[now];
                }
                else if(L[now]==-1 && R[now]==-1)break;
                else
                {
                    for(i=19;i>=0;i--)if(level[par[now][i]] <= X)
                    {
                        H = level[par[now][i]];
                        now = par[now][i];
                    }
                }

            }
            printf("%d\n",now);
        }
    }
}
/*
9 5
3 -1
-1 -1
1 8
6 7
-1 -1
-1 -1
5 4
-1 2
-1 -1
1 8 10 10
2 8 10 10
3 8 10 10
4 8 10 10
5 8 10 10

9 5
3 -1
-1 -1
1 8
6 7
-1 -1
-1 -1
5 4
-1 2
-1 -1
2 100 1 1
4 8 10 10
4 8 1 8
10 8 1 8
10 100 10 1

9 5
1 -1
-1 2
-1 3
4 -1
5 -1
6 -1
7 -1
-1 8
-1 -1



*/
