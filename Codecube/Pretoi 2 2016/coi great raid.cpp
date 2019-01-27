#include<stdio.h>
#include<algorithm>
using namespace std;
struct node
{
    int x,y
};
bool cmp(node a,node b)
{
    return a.y<b.y;
}
int head[100005];
int fh(int x)
{
    if(head[x]==x)return head[x];
    else return fh(head[x]);
}
node tab[1000005];
int a[100000];
main()
{
    int n,i,j,k,m,ans;
    ans = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&tab[i].x,&tab[i].y);
    }
    sort(&tab[0],&tab[m],cmp);
    for(i=0;i<n;i++)head[i]=i;
    for(i=0;i<m;i++)
    {
        if(fh[tab[i].x] == fh[tab[i].y])
        {
            ans = ans + a[tab[i].x] + a[tab[i].y];
        }
        else
        {
            head[fh(tab[i].x)] = head[fh(tab[i].y)];
        }
    }
    printf("%d",ans);
}
