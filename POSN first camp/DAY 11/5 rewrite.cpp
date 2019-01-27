#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
main()
{
    FILE *fp,*fp2;
    char x[100],c,buffer[100];
    int i;
    if((fp2 =fopen("data5.txt","w"))==NULL)
       {
        printf("Eror Create file");
        getch();
        exit(1);
       }
       else
        {
            gets(x);
            for(i=0;x[i]!='\0';i++)
            {
                fputc(x[i],fp2);
            }
            fclose(fp2);
            fp =fopen("data5.txt","r");
            fgets(buffer,strlen(x)+1,fp);
            printf("%s",buffer);
        }
}

