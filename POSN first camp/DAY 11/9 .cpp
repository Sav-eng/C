#include<stdio.h>
main()
{
    int n,a,i;
    scanf("%d %d",&n,&a);
    for(i=0;i<a;i++)
    {
        if(i%n<10)printf("%d",i%n);
        else
        {
            printf("%c",i%n-10+'A');
        }
    }
}
