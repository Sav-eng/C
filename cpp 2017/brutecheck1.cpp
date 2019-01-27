#include<bits/stdc++.h>
using namespace std;
int cx[] = {0,0,1,-1};
int cy[] = {1,-1,0,0};
int vis[301][301];
int tab[301][301];
int mem[301][301];
int n,m;
void FF(int x,int y)
{
    if(x==-1 || y==-1 || x==n || y==m)return;
    else if(!vis[x][y])
    {
        int i;
        vis[x][y] = 1;
        bool check=0;
        for(i=0;i<4;i++)
        {
            if(!tab[x+cx[i]][y+cy[i]])
            {
                //printf("\t %d %d\n",x+cx[i],y+cy[i]);
                FF(x+cx[i],y+cy[i]);
            }
        }
        //printf("%d %d\n",x,y);
    }

}
int mem2[301][301];
int FF2(int x,int y)
{
    if(x== -1 || y==-1 || x==n || y==m)return 0;
    //printf("\t\t%d %d\n",x,y);
    vis[x][y] = 1;
    mem2[x][y]= 1;
    for(int i=0;i<4;i++)
    {
        if(!vis[x+cx[i]][y+cy[i]] && !tab[x+cx[i]][y+cy[i]])
        {
            mem2[x][y] += FF2(x+cx[i],y+cy[i]);
        }
    }
    return mem2[x][y];
}
int CHECK(int x,int y)
{
    int ans=0;
    for(int i=0;i<4;i++)
    {
        if(vis[x+cx[i]][y+cy[i]])
        {
            if(!vis[x][y])ans+= FF2(x,y);
        }
        else if(x+cx[i]==-1 || y+cy[i] == -1 || x+cx[i] == n || y+cy[i]==m)
        {
            if(!vis[x][y])ans += FF2(x,y);
        }
    }
    //printf("x = %d y = %d ans = %d\n",x,y,ans);
    return ans;
}
int X[90001];
int Y[90001];
int Ans[90001];
int main()
{
    int T,i,j,x,y;
    int sum,ans=0;
    scanf("%d%d%d",&n,&m,&T);
    for(i=0;i<T;i++)
    {
        scanf("%d%d",&X[T-1-i],&Y[T-1-i]);
        tab[X[T-1-i]][Y[T-1-i]] = 1;// 1 mean rock
    }
    //printf("TEST");
    sum = n*m;
    memset(vis,0,sizeof(vis));
    memset(mem,0,sizeof(mem));
    //ans = sum;
    for(i=0;i<n;i++)
    {
        if(!tab[i][0])FF(i,0);
        if(!tab[i][m-1])FF(i,m-1);
    }
    for(j=0;j<m;j++)
    {
        if(!tab[0][j])FF(0,j);
        if(!tab[n-1][j])FF(n-1,j);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            //printf("%d",vis[i][j]);
            if(vis[i][j])ans++;
        }
        //printf("\n");
    }
    //printf("TEST");
    Ans[T-1] = ans;
    int t;
    for(i=1;i<T;i++)
    {
        //printf("i= %d\n",i);
        tab[X[i-1]][Y[i-1]] = 0;
        t = CHECK(X[i-1],Y[i-1]);
        ans+=t;
        Ans[T-1-i] = ans;
        //printf("\n");
    }
    for(i=0;i<T;i++)printf("%d\n",Ans[i]);
}
/*

5 5 8
0 0
0 1
0 2
1 2
2 2
2 1
2 0
1 0


*/
