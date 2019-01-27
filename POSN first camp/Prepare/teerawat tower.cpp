#include<stdio.h>
main()
{
    int n,check=1,i,check1=0,j,count=0;
    int nc,sp=3,cs=0,ac[100]={};
    char ch='A';
    scanf("%d",&n);
    nc = n;
    while(nc>0)
    {
        nc-=sp;
        sp++;
        cs++;
    }
    for(i=0;i<cs;i++)
    {
        printf(" ");
    }
    for(i=0;count<n;i++)
    {
        if(i%2!=0)
        {
            for(j=0;j<cs;j++)
            {
                printf(" ");
            }
        }
        else if(i!=0)
        {
            for(j=0;j<sp-i-3;j++)
            {
                printf(" ");
            }
        }
        for(j=0;j<=i;j++)
        {
            if(i%2==0 && i!=0)ac[j]=ch;
            else printf("%c",ch);
            count++;
            if(count==n)break;
            ch++;
            if(ch>'Z')ch='A';
        }
        if(i%2==0 && i!=0)
        {
            for(j=i;j>=0;j--)
            {
                if(ac[j]==' ')printf(" ");
                else printf("%c",ac[j]);
            }

        }
        for(j=0;j<100;j++)
        {
            ac[i]=' ';
        }
        printf("\n");
    }
}
