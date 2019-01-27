#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
main()
{
    FILE *fp,*fp2;

    if((fp=fopen("data2.txt","r"))==NULL || (fp2 =fopen("data4.txt","w"))==NULL)
       {
        printf("Eror Create file");
        getch();
        exit(1);
       }
       else
        {
            printf("Success\n");
            while(!feof(fp))
            {
                char c;
                c = fgetc(fp);
                fputc(c,fp2);
            }

        }
}

