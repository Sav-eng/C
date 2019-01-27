#include<bits/stdc++.h>
using namespace std;
int a[5001][5001];
int sum[5001][5001];
int tab[5001];
char s[5001];
bool cmp(int x,int y)
{
    return x>y;
}
main()
{
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%s",s);
        for(j=0;j<m;j++)
        {
            a[i][j] = s[j]-'0';
            sum[i][j] = (a[i][j]==1)?1+sum[i][j-1]:0;
        }
    }
    /*for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d ",sum[i][j]);
        }
        printf("\n");
    }*/
    int ans = 0;
    int x;
    for(j=0;j<m;j++)
    {
        for(i=0;i<n;i++)tab[sum[i][j]]++;
        //printf("--->");
        x=m;
        for(i=0;i<n;i++)
        {
            while(tab[x]==0 && x>0)x--;
            //printf("%d ",x);
            ans = max(ans,x*(i+1));
            tab[x]--;
        }
        //printf("\n");
        for(i=0;i<n;i++)tab[i] = 0;
    }
    /*for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d ",sum[i][j]);
        }
        printf("\n");
    }*/
    printf("%d",ans);
}
/*

5 7
1111111
1111111
1111111
1111111
1111111


*/
