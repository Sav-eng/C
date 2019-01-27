#include<stdio.h>
main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++) printf(" ");
        for(j=0;j<i*2+1;j++)
        {
            if(i==0)printf("*");
            else if(j==i*2)printf("\\");
            else if(j==0)printf("/");
            else printf("%d",i);
        }
        printf("\n");
    }
}
