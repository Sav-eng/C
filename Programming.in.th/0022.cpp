#include<stdio.h>
main()
{
    char a[1000][1000];
    int n,i,j,m,g;
    scanf("%d",&n);
    if(n%2==0)m=n-1;
    else m = n;
    if(m>=5)g=
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            a[i][j] = '_';
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(j - i == m/2 || i -j == m/2 || i+j == m/2 || i+j == g)a[i][j]='*';
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
}
