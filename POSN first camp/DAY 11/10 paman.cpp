#include<stdio.h>
#include<string.h>
main()
{
    int a,b,i,j,check=0;
    char x[10],ch;
    gets(x);
    scanf("%d %d",&a,&b);
    for(i=0;i<b;i++)
    {
        for(j=check;j<a+check;j++)
        {
            ch = x[j%strlen(x)];
            printf("%c",ch);
        }
        printf("\n");
        check++;
    }
}
