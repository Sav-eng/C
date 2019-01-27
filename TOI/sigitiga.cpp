#include<bits/stdc++.h>
using namespace std;
char x[256];
int a[256];
struct node
{
    int check[3]={0};
    node()
    {
        int i;
        for(i=0;i<3;i++)
        {
            check[i] = false;
        }
    }
};
node mem[256][256];
bool vis[256][256];
int tab[3][3];
node combine(node x,node y)
{
    node t;
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            //printf("tab[%d(%d)][%d(%d)] = %d\n",x.check[i],i,y.check[j],j,tab[x.check[i]][y.check[j]]);
            if(x.check[i] && y.check[j])t.check[tab[i][j]] = 1;
        }
    }
    return t;
}
node f(int l,int r)
{
    if(l==r)
    {
        mem[l][r].check[0] = 0;
        mem[l][r].check[1] = 0;
        mem[l][r].check[2] = 0;
        mem[l][r].check[a[l]] = 1;
        //printf("check[%d] = 1\n",a[l]);
        return mem[l][r];
    }
    else if(!vis[l][r])
    {
        int i,j;
        vis[l][r] = 1;
        for(i=0;i<3;i++)mem[l][r].check[i]=0;
        for(i=l;i<r;i++)
        {
            node t=combine(f(l,i),f(i+1,r));
            for(j=0;j<3;j++)
            {
                if(t.check[j])mem[l][r].check[j]=1;
            }
        }
        //printf("----%d-----%d----\n",l,r);
        //for(i=0;i<3;i++)printf("%d ",mem[l][r].check[i]);
        //printf("\n");
    }
    return mem[l][r];
}
main()
{
    int n,i,time=20;
    while(time--)
    {
        memset(vis,0,sizeof(vis));
        tab[0][0] = 2; tab[0][1]=1; tab[0][2]=0;
        tab[1][0] = 2; tab[1][1]=1; tab[1][2]=1;
        tab[2][0] = 1; tab[2][1]=2; tab[2][2]=1;
        scanf("%d",&n);
        scanf(" %s",x);
        for(i=0;i<n;i++)
        {
            a[i] = x[i]-'0';
        }
        node t = f(0,n-1);
        node();
        if(t.check[0])printf("yes\n");
        else printf("no\n");
    }
}
