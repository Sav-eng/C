#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,ord;
    char ch;
};
struct node2
{
    int x,ch;
};
int _x;
bool cmp(node x,node y)
{
    if(fabs(_x-x.x)==fabs(_x-y.x))return x.ord<y.ord;
    return fabs(_x-x.x)<fabs(_x-y.x);
}
bool cmp2(int x,int y)
{
    return x<y;
}
node tab[1001];
node2 mem[1001];
vector<char>p[1000001];
main()
{
    int n,T,m,i;
    scanf("%d%d",&n,&T);
    for(i=0;i<n;i++)
    {
        mem[i].ch = 'A'+i;
    }
    while(T--)
    {
        scanf("%d%d",&_x,&m);
        memset(tab,0,sizeof(tab));
        for(i=0;i<m;i++)
        {
            scanf(" %c%d",&tab[i].ch,&tab[i].x);
            tab[i].ord=i;
        }
        sort(&tab[0],&tab[m],cmp);
        for(i=0;i<m;i++)
        {
            //printf("\t%d %d\n",tab[i].x,_x);
            if(tab[i].x==_x)mem[tab[i].ch-'A'].x+=3;
            if(i<3)mem[tab[i].ch-'A'].x +=(3-i);
        }
    }
    for(i=0;i<n;i++)
    {
        p[mem[i].x].push_back(mem[i].ch);
    }
    for(i=0;i<=6000;i++)sort(p[i].begin(),p[i].end(),cmp2);
    int j;
    for(i=6000;i>=0;i--)
    {
        if(p[i].size()>0)
        {
            printf("%d ",i);
            for(j=0;j<p[i].size();j++)printf("%c ",p[i][j]);
            printf("\n");
        }
    }
}
/*

5 1
25 1 B 1000000

*/
