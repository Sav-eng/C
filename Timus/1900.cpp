#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
int n,m;
int a[502][502];
int tab[502][502];
int mem[502][502];
int trac[502][502];
int f(int x,int y)
{
    if(y==m)return 0;
    //else if(x==n && y!=m)return -inf;
    else if(!mem[x][y])
    {
        mem[x][y] = -1;
        int i,t;
        for(i=x;i<n;i++)
        {
            t = f(i+1,y+1)+tab[x][n-1]-tab[x][i-1]-tab[i+1][n-1];
            if(mem[x][y]<t)
            {
                mem[x][y] = t;
                trac[x][y] = i;
            }
            /*mem[x][y] = max(mem[x][y],f(i+1,y+1)+tab[x][n-1]-tab[x][i-1]-tab[i+1][n-1]);
            if(mem[x][y]==f(i+1,y+1)+tab[x][n-1]-tab[x][i-1]-tab[i+1][n-1])trac[x][y] = i;*/
        }
        //printf("mem[%d][%d] = %d\n",x,y,mem[x][y]);
    }
    return mem[x][y];
}
main()
{
    int i,j,k,t=0;
    scanf("%d%d",&n,&m);
    for(i=1;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=1;i<n;i++)//start in i--k and end in i--k
    {
        for(j=i;j<n;j++)
        {
            t = 0;
            for(k=i;k<=j;k++)t+=a[k][j];
            tab[i][j] = tab[i][j-1]+t;
        }
    }
    /*for(i=1;i<n;i++)
    {
        for(j=1;j<n;j++)
        {
            printf("%d ",tab[i][j]);
        }
        printf("\n");
    }*/
    printf("%d\n",f(1,0));
    t = 1;
    i= 0;
    while(trac[t][i]!=0)
    {
        printf("%d ",trac[t][i]);
        t = trac[t][i++];
        t++;
    }
}
/*
4 3
1000 2 0
2 5
1000

*/
