#include<stdio.h>
main()
{
    int i;
    char c[20];
    gets(c);
    for(i=0;i<20;i++)
    {
        if(c[i]>'Z')printf("%c",c[i]-0x20);
        else printf("%c",c[i]);
    }
}
