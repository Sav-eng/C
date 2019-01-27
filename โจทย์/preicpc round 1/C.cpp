#include<bits/stdc++.h>
using namespace std;
int cx[]={0,0,1,-1};
int cy[]={1,-1,0,0};
int a[101][101];
int b[101][101];
int n,m;
bool check(int x,int y)
{
    if(x>=0 && y>=0 && x<n && y<m)return 1;
    return 0;
}
main()
{
    int i,j,o,t,t2;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[i][j]==0)
            {
                t=0;
                t2=0;
                for(o=0;o<4;o++)
                {
                    if(a[i+cx[o]][j+cy[o]] && check(i+cx[o],j+cy[o]))
                    {
                        t2++;
                        t += a[i+cx[o]][j+cy[o]];
                    }
                }
                if(t2==0)b[i][j] = 0;
                else b[i][j] = t/t2;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[i][j]==0)printf("%d ",b[i][j]);
            else printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
