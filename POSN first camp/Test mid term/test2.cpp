#include<stdio.h>
main()
{
    int x,y;
    char ch ='A';
    for(x=1;x<=20;x++)
    {
        y = x%4;
        switch(y)
        {
            case 0:
                ch++;
                break;
            case 1:
                ch++;
            case 2:
                ch++;
                break;
            case 3:
                ch++;
                break;
        }
        if((x%6)==0)
            printf("Output = %c\n",ch);
    }
}
