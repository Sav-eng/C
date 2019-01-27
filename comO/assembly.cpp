#include<bits/stdc++.h>
using namespace std;
const int MAXN = 201;
const int inf = 2e9;
struct node
{
    int x;
    char y;
};
int x[MAXN];
char X[MAXN];
char y[MAXN];
int tab[MAXN][MAXN];
char tab2[MAXN][MAXN];
node mem[MAXN][MAXN];
char a[MAXN];
node f(int l,int r)
{
    if(l==r)return {0,X[l]};
    else if(r-l==1)
    {
        //printf("(%d,%d)return %d,%c\n",l,r,tab[X[l]][X[r]],tab2[X[l]][X[r]]);
        return {tab[X[l]][X[r]],tab2[X[l]][X[r]]};
    }
    else if(mem[l][r].x==0)
    {
        int i;
        mem[l][r].x = inf;
        for(i=l;i<r;i++)
        {
            node t = f(l,i);
            node t2 = f(i+1,r);
            node t3;
            //printf("%d---%d + %d---%d =  %d[%c][%c]\n",l,i,i+1,r,tab[t.y][t2.y],t.y,t2.y);
            t3.x = t.x+t2.x+tab[t.y][t2.y];
            t3.y = tab2[t.y][t2.y];
            if(mem[l][r].x>t3.x)mem[l][r] = t3;
        }
    }
    //printf("mem[%d][%d] = %d,%c\n",l,r,mem[l][r].x,mem[l][r].y);
    return mem[l][r];
}
main()
{
    int n,i,j,m,N;
    while(scanf("%d",&n) && n)
    {
        for(i=0;i<n;i++)scanf(" %c",&a[i]);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d-%c",&x[i],&y[i]);
                tab[a[i]][a[j]] = x[i];
                tab2[a[i]][a[j]] = y[i];
                //printf("%d %c\n",x[i],y[i]);
            }
        }
        scanf("%d",&m);
        while(m--)
        {
            memset(mem,0,sizeof(mem));
            scanf("%s",&X);
            N = strlen(X);
            node ans = f(0,N-1);
            printf("%d-%c\n",ans.x,ans.y);
        }
        printf("\n");
    }
}
