#include<bits/stdc++.h>
using namespace std;
int vis[126][126];
int cx[] = {-1,1,-1,1};
int cy[] = {1,1,-1,-1};
int n,m,all,cnt2;
void f(int x,int y,int lastx,int lasty)
{
    int i,X,Y,cnt=0;
    vis[x][y] = 1;
    printf("%d %d\n",x,y);
    cnt2++;
    for(i=0;i<4;i++)
    {
        int X = x+cx[i], Y = y+cy[i];
        if(!vis[X][Y] && X>0 && Y>0 && X<=n && Y<=m)
        {
            //cnt++;
            f(X,Y,x,y);
        }
    }
    if(cnt2!=all)printf("%d %d\n",lastx,lasty);
    //vis[x][y] = 0;
}
main()
{
    freopen("b1.in","r",stdin);
    freopen("b1.out","w",stdout);
    int T;
    char c;
    int i;
    scanf("%d",&T);
    while(T--)
    {
        memset(vis,0,sizeof(vis));
        scanf("%d%d %c",&n,&m,&c);
        cnt2 = 0;
        if(n==1 || m==1)
        {
            printf("impossible\n\n");
            continue;
        }
        if(((n*m)%2)!=0)all = (c=='B')?(n*m)/2:(n*m)/2+1;
        else all = (n*m)/2;
        //printf("all = %d\n",all);
        if(c=='B')
        {
            f(2,1,0,0);
        }
        else
        {
            f(1,1,0,0);
        }
        printf("\n");
    }
}

/*
3
2 6 B
1 3 W
5 5 W

*/
