#include<stdio.h>
main()
{
    int i = 0,check=1,j,co=0;
    char c[200],cc[200];
    while(c[i]!='0')
    {
        scanf("%c",&c[i]);
        if(c[i]=='0')break;
        if(c[i]!=c[i-check])
        {
            cc[i-co]=c[i];
            check = 1;
        }
        else
            {
                check++;
                co++;
            }
        i++;
    }
    for(j=0;j<i;j++)
    {
        if(c[i]!=' ')printf("%c",cc[j]);
    }

}
