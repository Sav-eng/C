#include<stdio.h>
main()
{
    int n,m,k,check=0,checkdesk=0,checklane=1;
    char ansc;
    scanf("%d%d%d",&n,&m,&k);
    while(k>0)
    {
        if(checkdesk==m && ansc == 'R')
        {
            checkdesk = 0;
            checklane++;
        }

        if(check%2==1)
        {
            ansc = 'R';
        }
        else
        {
            ansc = 'L';
            checkdesk++;
        }check++;
        k--;


    }
    printf("%d %d %c",checklane,checkdesk,ansc);
}
