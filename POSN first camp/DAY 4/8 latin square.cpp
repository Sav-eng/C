#include<stdio.h>
main()
{
    int n,i,j,s;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=0;j<n;j++)
        {
            s = i+j;
            if(s>n)s = s-n;
            printf("%d",s);

        }
        printf("\n");
    }
}
