#include<stdio.h>
#include<string.h>
main()
{
    scanf("%d",&n);
    gets(a);
    gets(b);
    if(n=16)printf("%x",a+b);
    else if(n=10)printf("%d",a+b);
    else
    {
        x = strlen(a);
        y = strlen(b);
        for(i=0;i<x;i++)
        {
            temp = a1[i];
            a1[i] = a1[n-i];
            a1[n-i] = temp;
        }
        for(i=0;i<y;i++)
        {
            temp = b1[i];
            b1[i] = b1[n-i];
            b1[n-i] = temp;
        }
        if(y>x)x=y;
        for(i=0;i<x;i++)
        {
            ans[i] += a1[i]+b1[i];
            if(ans[i]>n)
            {
                ans[i] = ans[i]%n
                ans[i+1]+=1;
            }
        }


    }
}
