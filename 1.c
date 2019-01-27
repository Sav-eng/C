#include<stdio.h>
main()
{
    int i,j,m,n,s=65;
    scanf("%d %d",&m,&n);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%c",s);
            s++;
            if(s==90)s=65;


        }
        printf("\n");
    }
}
