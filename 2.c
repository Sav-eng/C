#include<stdio.h>
main()
{
    int i,j,n,s=65;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j || i==n-j-1)
            {
                 printf("%c",s);
            }
            else
                printf(" ");
        }
        s++;
        if(s==91)s=65;
        printf("\n");
    }

}
