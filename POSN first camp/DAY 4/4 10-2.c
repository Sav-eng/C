#include<stdio.h>
main()
{
    int i=0,x,b[17],check=0;
    scanf("%d",&x);
    while(x!=0)
    {
        b[i] = x%2;
        x = x/2;
        check++;
        i++;
    }
    for(i=0;i<check;i++)
    {
        printf("%d",b[i]);
    }
}
