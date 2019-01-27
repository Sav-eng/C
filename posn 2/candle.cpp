#include<stdio.h>
int cx[8]={0,1,1,-1,0,-1,1,-1};
int cy[8]={1,0,1,-1,-1,0,-1,1};
int n,m;
int a[2005][2005];
char st[2005][2005];
void f(int i,int j)
{
    int _i;
    a[i][j]=0;
    //printf("%d %d\n",i,j);
    if(i<0 || j<0 || i>=n || j>=m) return;
    //printf("%d %d\n",i,j);
    for(_i=0;_i<8;_i++)
    {
        if(a[i+cx[_i]][j+cy[_i]]==1)
        {
            //printf("check");
            f(i+cx[_i],j+cy[_i]);
        }
    }
}
main()
{
    int sum=0;
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%s",&st[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            a[i][j] = st[i][j]-'1'+1;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[i][j]==1)
            {
                sum++;
            //printf("i=%dj=%d\n",i,j);
                f(i,j);
            }
        }
    }
    //
    printf("%d",sum);
}
/*
4 5
10011
00001
01100
10011
*/
