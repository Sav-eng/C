#include<stdio.h>
char x[100000];
char space[] = {"SPACEBAR"};
char shift[] = {"SHIFT"};
main()
{
    int n,i,ans,check;
    scanf("%d ",&n);
    gets(x);
    i = 0;
    ans = 0;
    while(i<n)
    {
        check = 0;
        while(space[check]==x[i])
        {
            i++;
            check++;
            if(check==8)break;
        }
        if(check==8)
        {
            ans++;
            //printf("%dspace",i);
            continue;
        }
        else
        {
            //printf("%ddelete%d\n",i,check);
            i-=check;
        }
        check = 0;
        while(shift[check]==x[i])
        {
            i++;
            check++;
            if(check==5)break;
        }
        if(check==5)
        {
            ans++;
            //printf("%dshift",i);
            continue;
        }
        else
        {
            //printf("%ddelete%d\n",i,check);
            i-=check;
        }
        if(x[i]=='Q' || x[i] == 'W' || x[i] == 'E' || x[i] == 'A' || x[i] == 'S' || x[i] == 'D' || x[i] == 'V')
        {
            ans++;
            //printf("%d ",i);
        }
        //printf("%c = %d\n",x[i],i);
        i++;
    }
    printf("%d",ans);
}
