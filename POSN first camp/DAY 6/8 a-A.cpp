#include<stdio.h>
main()
{
    int i=0;
    char c[100];
    gets(c);
    while(c[i]!='\0')
    {
        if(c[i]>'Z')c[i] = c[i]-0x20;
        printf("%c",c[i]);
        i++;
    }
}
