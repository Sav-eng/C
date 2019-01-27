#include<stdio.h>
main()
{
    struct people
    {
        char name[20],nam[20];
        int old;
    };
    struct people p[20];
    int i,j=0;
    for(i=0;i<10;i++)
    {
        scanf("%s",p[i].name);
        scanf("%s",p[i].nam);
        scanf("%d",&p[i].old);
        /*puts(p[i].name);
        puts(p[i].nam);
        printf("%d\n",p[i].old);*/
    }
    for(i=0;i<10;i++)
    {
        while(p[i].name[j]!='\0')
        {
            if(p[i].name[j] == 'P' || p[i].name[j] == 'p')
            {
                printf("%s %s\n",p[i].name,p[i].nam);
                j++;
                break;
            }
            if(p[i].nam[j] == 'P' || p[i].nam[j] == 'p')
            {
                printf("%s %s\n",p[i].name,p[i].nam);
                j++;
                break;
            }
            j++;
        }
        j=0;
    }
}
