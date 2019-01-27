#include<stdio.h>
char a[15];
bool tab[15][15];
main()
{
    freopen("cowtip.in","r",stdin);
    freopen("cowtip.out","w",stdout);
    int n,i,j,_i,_j,ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",a);
        for(j=0;j<n;j++)
        {
            tab[i][j] = a[j]-48;
        }
    }
    for(i=n-1;i>=0;i--)
    {
        for(j=n-1;j>=0;j--)
        {
            if(tab[i][j]==1)
            {
                for(_i=0;_i<=i;_i++)
                {
                    for(_j=0;_j<=j;_j++)
                    {
                        tab[_i][_j] =!tab[_i][_j];
                    }
                }
                ans++;
                /*for(_i=0;_i<n;_i++)
                {
                    for(_j=0;_j<n;_j++)
                    {
                        printf("%d ",tab[_i][_j]);
                    }
                    printf("\n");
                }
                printf("\n");*/
            }
        }
    }
    printf("%d",ans);

}
