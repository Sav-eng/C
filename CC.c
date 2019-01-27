#include<stdio.h>
char CC(char c)
{
    if(c>=65 && c<=90)return 'r';
    else
    return 'w';
}

main()
{
    int c;
    scanf("%c",&c);
    printf("%c",CC(c));
}
