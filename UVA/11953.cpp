#include<bits/stdc++.h>
using namespace std;
int cx[] = {0,0,-1,1};
int cy[] = {1,-1,0,0};
int tab[105][105];
int f(int x,int y)
{
    int i;
    for(i=0;i<4;i++)
    {
        if(tab[x+cx[i]][y+cy[i]]=='x' || tab[x+cx[i]][y+cy[i]] == '@')
        {
            tab[x+cx[i]][y+cy[i]] = '.';
            f(x+cx[i],y+cy[i]);
        }
    }
}
main()
{
    int time,i,j,ans,n,check=0;
    scanf("%d",&time);
    while(time--)
    {
        memset(tab,0,sizeof(tab));
        ans = 0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf(" %c",&tab[i][j]);
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(tab[i][j]=='x')
                {
                    ans++;
                    tab[i][j] = '.';
                    f(i,j);
                }
            }
        }
        check++;
        printf("Case %d: %d\n",check,ans);
    }
}
