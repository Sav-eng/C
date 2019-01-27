#include<stdio.h>
main()
{
    int n,i,m,j,t;
    int check;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        check=0;
        m=0;n=0;
        scanf("%d%d",&n,&m);
        if(m>n)m=n;
        check = m/20;
        printf("Case #%d: %d \n",i+1,check+1);
    }
}
