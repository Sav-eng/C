#include<stdio.h>
main()
{
    int x,y = 4;
    char ch1[5];
    char ch = 'A';
    for(x=1;x<=25;x++)
    {
        ch++;
        if((x%5)==0)
        {
            ch1[y] = ch;
            y--;
        }
    }
    printf("%c \n",ch1[1]);
    printf("%c \n",ch1[2]);
    printf("%c \n",ch1[3]);
}
