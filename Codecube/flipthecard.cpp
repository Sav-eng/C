#include<stdio.h>
int a[1005][2];
int b[1005];
bool c[1005];
main()
{
    int n,m,j,i;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&a[i][0],&a[i][1]);
    }
    for(i=0;i<m;i++)
    {
        scanf("%d",&b[i]);
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[j][c[j]]<=b[i])
            {
                c[j]= !c[j];
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i][c[i]]);
    }
}
