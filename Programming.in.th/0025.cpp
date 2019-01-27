
#include<stdio.h>
#include<string.h>
main()
{
    char a[1000],b[10000],o;
    int na,nb,max,min,i;
    scanf("%s %c %s",&a,&o,&b);
    na = strlen(a);
    nb = strlen(b);
    if(na>nb)
    {
        max = na;
        min = nb;
    }
    else
    {
        max = nb;
        min = na;
    }
    if(o == '*')
    {
        printf("1");
        for(i=0;i<na+nb-2;i++)printf("0");
    }
    else
    {
        if(max==min)
        {
            printf("2");
            for(i=0;i<min-1;i++)printf("0");
        }
        else
        {
            printf("1");
            for(i=1;i<max;i++)
            {
                if(i==max-min)printf("1");
                else printf("0");
            }
        }
    }
}
