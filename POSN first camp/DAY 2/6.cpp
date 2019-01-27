#include<stdio.h>
main()
{
    int a,i;
    scanf("%d",&a);
    for(i=2;i<a;i++)
    {
        if(a%i==0)
        {
            printf("No");
            break;
        }
        else
        printf("Prime number");
        break;

    }

}
