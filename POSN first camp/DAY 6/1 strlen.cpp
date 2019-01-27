#include<stdio.h>
main()
{
    char c[20];
    int i=0;
    gets(c);
    while(c[i]!='\0')
    {
        i++;
    }
    printf("%d",i);

}
