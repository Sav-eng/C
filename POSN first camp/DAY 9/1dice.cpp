#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
main()
{
    char a='y';
    srand(time(NULL));
    while(1)
    {
        printf("Your dice is %d\n",rand()%6+1);
        printf("Do you want more(y/n):\n");
        a = getch();
        if(a=='n' || a!= 'y')break;
    }


}
