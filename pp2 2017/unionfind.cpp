#include<stdio.h>
int head[1000];
int findhead(int x)
{
    if(x==head[x])return x;
    else return head[x] = findhead(head[x]);
}
main()
{
    int n,m,i,a,x,y;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)head[i]=i;
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&a,&x,&y);
        if(a==1)
        {
            printf("\t%d\n",findhead(head[x])==findhead(head[y]));
        }
        else
        {
            head[findhead(x)] = findhead(head[y]);
        }
    }
}
