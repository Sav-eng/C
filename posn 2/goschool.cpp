#include<stdio.h>
bool tab[100][100];
bool visit[100][100];
int n,m;
long long mem[100][100];
bool check[100][100];
long long f(int x,int y)
{
    //printf("A");
    if(mem[x][y]!=0)return mem[x][y];
    if(x == n-1 && y == m-1)
    {
        return 1;
    }
    if(x>=n||y>=m)return 0;
    if(tab[x+1][y] == 0 && x<n)
    {
        mem[x][y] += f(x+1,y);
    }
    if(tab[x][y+1]==0 && y <m)
    {
        mem[x][y] += f(x,y+1);
    }
    return mem[x][y];
}
main()
{
    int k;
    int j,i;
    int x,y;
    scanf("%d%d",&m,&n);
    scanf("%d",&k);
    for(i=0;i<k;i++)
    {
        scanf("%d%d",&x,&y);
        tab[y-1][x-1]=1;
    }
    printf("%lld\n",f(0,0));

}

