#include<stdio.h>
main()
{
    int n,i,prime,j,cnt;
    scanf("%d",&n);
    i = 1;
    while(1)
    {
        prime = (n*i)+1;
        cnt = 1;
        for(j=2;j<prime;j++)
        {
            if(prime%j==0)
            {
                cnt =0;
            }
        }
        if(cnt==1)i++;
        else
        {
            printf("%d",i);
            return 0;
        }
    }
}
