#include<stdio.h>
main()
{
    int i=0,ab=0;
    char num[20];
    gets(num);
    while(num[i]!='\0')
    {
        num[i] = num[i]-'0';
        ab = ab*10+num[i];
        i++;
    }
    printf("%d",ab*2);

}
