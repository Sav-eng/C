#include<stdio.h>
#include<string.h>
main()
{
    int n,i,j;
    char x[100];
    bool wrong,time,mem;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",&x);
        wrong =0;
        time = 0;
        mem = 0;
        for(j=0;j<strlen(x);j++)
        {
            if(x[j]=='-')wrong =1;
            else if(x[j]=='T')time=1;
            else if(x[j]=='X')mem=1;

        }
        if(mem)
        {
            printf("Case #%d: No - Runtime error\n",i+1);
            continue;
        }
        if(time)
        {
            printf("Case #%d: No -  Time limit exceeded\n",i+1);
            continue;
        }
        if(wrong)
        {
            printf("Case #%d: No - Wrong answer\n",i+1);
            continue;
        }
        else
        {
            printf("Case #%d: Yes\n",i+1);
        }
    }
}
