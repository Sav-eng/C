#include<stdio.h>
char ans[150000];
main()
{
    int n,a,k,b,i,checka,checkb;
    scanf("%d%d%d%d",&n,&k,&a,&b);
    checka = a;
    checkb = b;
    for(i=k;i<n;i+=k+1)
    {
        if(a<b)
        {
            checka--;
            ans[i]='G';
        }
        else
        {
            checkb--;
            ans[i]='B';
        }
    }
    if(checka < 0 || checkb < 0)
    {
        printf("NO");
        return 0;
    }
    for(i=0;i<n;i++)
    {
        if(a<=b)
        {
            if(ans[i]!='G')
            {
                if(checka>0)
                {
                    checka--;
                    printf("G");
                }
                else printf("B");
            }
            else printf("G");
        }
        else
        {
            if(ans[i]!='B')
            {
                if(checkb>0)
                {
                    checkb--;
                    printf("B");
                }
                else printf("G");
            }
            else printf("B");
        }
        //printf("%d %d\n",checka,checkb);
    }
}
/*

3 1 2 1

*/
