#include<stdio.h>
main()
{
    struct card
    {
        int num;
        char numc[10]="JQK";
        char d[10]="CDHS";
    };
    printf("C = clubs D = diamonds H = hearts S = spades\n");
    struct card a;
    a.num = 1;
    int i,j,check=0;
    for(i=0;i<13;i++)
    {
        for(j=0;j<4;j++)
        {
            if(a.num <= 10 )printf("%2d %c",a.num,a.d[j]);
            else
            {
                printf("%2c %c",a.numc[check],a.d[j]);
                if(j==3)check++;
            }
            printf("\n");

        }
        a.num++;
    }
}
