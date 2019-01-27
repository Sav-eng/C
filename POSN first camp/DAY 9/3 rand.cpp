#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
main()
{
    int i,a,count=0;
    srand(time(NULL));
    for(i=0;i<100;i++)
    {
        a = rand()%80+21;
        if(a%3==0)
        {
            printf("%d\n",a);
            count++;
        }
    }
    printf("count = %d",count);
    getch();
}
