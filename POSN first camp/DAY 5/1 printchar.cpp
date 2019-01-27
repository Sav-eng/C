#include<stdio.h>
main()
{
    int n,i;
    char c;
    scanf("%d",&n);
    c = 'A';
    for(i=0;i<n;i++)
    {
        printf("%c",c);
        c++;
    }
    c--;
    for(i=0;i<n;i++)
    {
        printf("%c",c);
        c--;
    }

}
