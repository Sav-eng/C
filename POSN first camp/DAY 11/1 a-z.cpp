#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
main()
{

    FILE *fp;
    char i;
    if((fp=fopen("data1.txt","w"))==NULL)
       {
        printf("Eror Create file");
        getch();
        exit(1);
       }
       else
        {
            printf("Success");
            for(i='A';i<='Z';i++)
            {
                fputc(i,fp);
            }
        }

}
