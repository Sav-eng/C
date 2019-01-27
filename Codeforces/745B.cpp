#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char a[1000][1000];
int tab[1000][1000];
main()
{
    int n,m,i,j,starti,startj;
    bool check = 0;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf(" %c",&a[i][j]);
        }
    }
    //printf("a");
    int l=0;
    int h=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            //printf("a");
            if(a[i][j] == 'X')
            {
                if(!check)
                {
                    starti = i;
                    startj = j;
                    check = 1;
                    tab[i-starti][j-startj] = 1;
                    l = max(i-starti,l);
                    h = max(j-startj,h);//printf("%d %d\n",l,h);
                }
                else if(i-starti < 0 || j-startj <0)
                {
                    printf("NO");
                    return 0;
                }
                else
                {

                    tab[i-starti][j-startj] = 1;
                    l = max(i-starti,l);
                    h = max(j-startj,h);//printf("%d %d\n",l,h);
                }
            }
        }
    }
    for(i=0;i<=l;i++)
    {
        for(j=0;j<=h;j++)
        {
            //printf("%d ",tab[i][j]);
            if(tab[i][j]==0)
            {
                printf("NO");
                return 0;
            }
        }
        //printf("\n");
    }
    if(check)printf("YES");
}
/*

3 3
.X.
.XX
.X.

*/
