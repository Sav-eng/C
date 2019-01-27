#include<stdio.h>
main()
{
    int a,b,i,check=1;
    scanf("%d %d",&a,&b);
    for(i=1;i<a;i++)
    {
        printf("   ");
        check++;
    }
    for(i=1;i<=b;i++)
    {
        if(i<10)printf(" ");
        printf(" %d",i);
        check++;
        if(check==8)
        {
            check = 1;
            printf("\n");
        }
    }
}
