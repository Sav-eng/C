#include<stdio.h>
main()
{
    int n,i,check;
    char ch;
    scanf("%d %c",&n,&ch);
    check = ch;
    for(i=0;i<n;i++)
    {
        if(check>'Z')check='A';
        printf("%c",check);

        check++;
    }
}
