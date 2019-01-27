#include<stdio.h>
main()
{
    int x[100][100],l,k,m,n,c,y=0,a,b,p,q,i,j;
    scanf("%d %d",&n,&m);
    scanf("%d %d",&l,&k);
    scanf("%d",&c);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&x[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            a = y + x[i][j];
            y = a;
        }
    }
    b =l*k*c;
    p = a+b;
    q = p/c;
        if(p-(q*c) != 0)
        {
            q = q+1;
        }
    printf("%d",q);
    return 0;
}

