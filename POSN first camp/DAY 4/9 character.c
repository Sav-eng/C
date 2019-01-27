#include<stdio.h>
main()
{
    int i=0,j,n;
    char check='A';
    scanf("%d",&n);
    while(i!=n)
    {
        for(j=0;j<i+1;j++)
        {
            if(check>'Z')check='A';
            printf("%c",check);
            check++;
        }
        printf("\n");
        i++;
    }
}
