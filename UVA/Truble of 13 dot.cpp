#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int mem[20000][1000];
int n,m;
struct node
{
    int val,fav;
};
bool cmp(node x,node y)
{
    return x.val<y.val;
}
node a[10000];
int f(int x,int y)
{
    if(y>=m)return 0;
    if(mem[x][y]!=0)return mem[x][y];
    //printf("f(%d,%d)\n",x,y);
    mem[x][y] = f(x,y+1);
    if(x+a[y].val>2000)
    {
        if(x+a[y].val<=n+200) mem[x][y] = max(mem[x][y],a[y].fav+f(x+ a[y].val ,y+1));
    }
    else if(x+a[y].val<n)mem[x][y] = max(mem[x][y],a[y].fav + f(x+a[y].val,y+1));

    return mem[x][y];
}
main()
{
    int i;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(mem,0,sizeof(mem));
        for(i=0;i<m;i++)scanf("%d%d",&a[i].val,&a[i].fav);
        sort(&a[0],&a[m],cmp);
        printf("%d\n",f(0,0));
    }
}
/*
1900 3
2000 5
1950 2
101 1
*/
