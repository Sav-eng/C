#include<stdio.h>
main()
{
    int n,i,ans=0,c2=0,c3=0;
    scanf("%d",&n);
    while(n>0)
    {
        if(n==3)
        {
            n-=3;
            ans++;
            c3++;
        }
        else if(n-2>=0)
        {
            n-=2;
            ans++;
            c2++;
        }
        //printf("%d",n);
    }
    printf("%d\n",ans);
    for(i=0;i<ans;i++)
    {
        if(c2>0)
        {
            printf("2 ");
            c2--;
        }

        else if(c3>0)
        {
            printf("3 ");
            c3--;
        }
    }
}
/*

5

6

*/
