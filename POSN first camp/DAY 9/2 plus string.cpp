#include<stdio.h>
main()
{
    int ai=0,bi=0,i;
    char a[10],b[10];
    gets(a);
    gets(b);
    i = 0;
    while(a[i]!='\0')
    {
        ai *= 10;
        ai += a[i]-'0';
        i++;
    }
    i=0;
    while(b[i]!='\0')
    {
        bi*=10;
        bi += b[i]-'0';
        i++;
    }
    printf("%d",ai+bi);
}
