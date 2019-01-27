#include<stdio.h>
#include<string.h>
main()
{
    int i=0,j=0,check=0;
    char x[10],a[5][50]={{}};
    gets(x);
    while(x[i]!='\0')
    {
        switch(x[i])
        {
            case '1':
                for(j=0;j<5;j++)
                    a[j][2+check]='*';
                break;
            case '2':
                for(j=0;j<3;j++)
                {
                    a[0][j+check] = '*';
                    a[2][j+check] = '*';
                    a[4][j+check] = '*';
                }
                a[1][2+check] = '*';
                a[3][check] = '*';
                break;
            case '3':
                for(j=0;j<3;j++)
                {
                    a[0][j+check] = '*';
                    a[2][j+check] = '*';
                    a[4][j+check] = '*';
                }
                a[1][2+check] = '*';
                a[3][2+check] = '*';
                break;
            case '4':
                for(j=0;j<5;j++)
                    a[j][2+check] = '*';
                for(j=0;j<3;j++)
                    a[j][check] = '*';
                a[2][check+1] = '*';
                break;
            case '5':
                for(j=0;j<3;j++)
                {
                    a[0][j+check] = '*';
                    a[2][j+check] = '*';
                    a[4][j+check] = '*';
                }
                a[1][check] = '*';
                a[3][check+2] = '*';
                break;
            case '6':
                for(j=0;j<5;j++)
                    a[j][check] = '*';
                for(j=0;j<3;j++)
                {
                    a[0][j+check] = '*';
                    a[2][j+check] = '*';
                    a[4][j+check] = '*';
                }
                a[3][check+2]= '*';
                break;
            case '7':
                for(j=0;j<5;j++)
                    a[j][check+2] = '*';
                for(j=0;j<3;j++)
                    a[0][check+j] = '*';
                break;
            case '8':
                for(j=0;j<3;j++)
                {
                    a[0][j+check] = '*';
                    a[2][j+check] = '*';
                    a[4][j+check] = '*';
                }
                for(j=0;j<5;j++)
                {
                    a[j][check]='*';
                    a[j][check+2]='*';
                }
                break;
            case '9':
                for(j=0;j<3;j++)
                {
                    a[0][j+check] = '*';
                    a[2][j+check] = '*';
                }
                for(j=0;j<5;j++)
                    a[j][check+2] = '*';
                a[1][check]='*';
                break;
            case '0':
                for(j=0;j<5;j++)
                {
                    a[j][check+2] = '*';
                    a[j][check] = '*';
                }
                a[0][check+1]='*';
                a[4][check+1]='*';
                break;
        }
        i++;
        check+=4;
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<strlen(x)*4;j++)
        {
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
}
