#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int head[30005];
int check[30005];
int ans;
int findhead(int x)
{
    if(x==head[x])return x;
    else return findhead(head[x]);
}
main()
{
    int time,n,m,i,x,y;
    scanf("%d",&time);
    while(time--)
    {
        ans = 0;
        memset(check,0,sizeof(check));
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)head[i]=i;
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            head[findhead(x)] = findhead(head[y]);
        }
        //for(i=1;i<=n;i++)printf("%d ",head[i]);
        for(i=1;i<=n;i++)
        {
            check[findhead(i)]++;
        }

        for(i=1;i<=n;i++)
        {
            ans = max(check[i],ans);
        }
        printf("%d\n",ans);
    }
}
/*
2
3 2
1 2
2 3
10 12
1 2
3 1
3 4
5 4
3 5
4 6
5 2
2 1
7 1
1 2
9 10
8 9

*/
