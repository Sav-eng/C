#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
main()
{
    struct card
    {
        int num;
        char ch;
    };
    struct card cc[20],a;
    int i=0,j=0,check=0,b=0,c[12],k,c1[12],check2=0;
    char ch[]= "♦♣♠♥",ch2[]="JQK";
    srand(time(NULL));
    while(check<10)
    {
        a.num = rand()%13+1;
        j = rand()%4;
        a.ch = ch[j];
        cc[i]=a;
        for(k=0;k<i;k++)
        {
            if(cc[i].num!=a.num && cc[i].ch != a.ch)check2++;
        }
        if(check2==i)
        {
            if(a.num<11)
            {
                printf("%d %c",a.num,a.ch);
                check++;
            }
            else
            {
                printf("%c %c",ch2[10-a.num],a.ch);
                check++;
            }
             printf("\n");
        }
        i++;

    }
}
