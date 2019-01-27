#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
main()
{
    int n,i,j;
    scanf("%d",&n);
    FILE *fp;
    if((fp=fopen("data2.txt","w"))==NULL)
       {
        printf("Eror Create file");
        getch();
        exit(1);
       }
       else
        {
            printf("Success");
            for(i=0;i<n;i++)
            {
                for(j=0;j<=i;j++)
                {
                    fputc('*',fp);
                }
                fputc('\n',fp);
            }
        }
}
