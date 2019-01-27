#include<stdio.h>
main()
{
    int i=0;
    char ch1[20],ch2[20];
    gets(ch1);
    for(i=0;i<20;i++)
    {
        ch2[i]=ch1[i];
    }
    printf("%s",ch2);
}
