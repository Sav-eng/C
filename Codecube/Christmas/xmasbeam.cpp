#include<stdio.h>
#define inf 1e9
struct node
{
    int x,y;
};
int abs(int x)
{
    if(x<0)return -x;
    return x;
}
bool cmp(node x,node y)
{
    return x.y<y.y;
}
node tab[150000];
int h;
main()
{
    scanf("%d",&time)
    while(time--)
    {
        scanf("%d%",&n,&h);
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&tab[i].x,&tab[i].y);
        }
        sort(tab[0],tab[n],cmp);

        printf("%d",ans);
    }
}
