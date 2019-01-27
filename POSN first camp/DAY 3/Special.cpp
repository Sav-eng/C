#include<stdio.h>

main()
{
    int a,n,i=0;
    char x[200];
    gets(x);
    scanf("%d",&a);
    while(x[i]!='\0')
    {
        if(x[i]+a>'Z')x[i]-=26;
        if(x[i]!=' ')printf("%c",x[i]+a);
        else printf(" ");
        i++;
    }


}
