#include<stdio.h>
main()
{
    int a,b,i,s,temp;
    scanf("%d %d",&a,&b);
    if(b>a)
    {
        temp = a;
        a = b;
        b = temp;
    }
    for(i=1;i<=b;i++)
    {
        if(a%i==0)
        {
            if(b%i==0)s = i;
        }
    }
    printf("%d \n",s);
    for(i=a*b;i>b;i--)
    {
        if(i%a==0)
        {
            if(i%b==0)s = i;
        }
    }
    printf("%d",s);

}
