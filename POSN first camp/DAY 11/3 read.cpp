#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
main()
{
    FILE *fp;
    if((fp=fopen("data2.txt","r"))==NULL)
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
                //single_char = fgetc(fp);
                char c;
                c = fgetc(fp);
                printf("%c",c);
            }

        }
}

