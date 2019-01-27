#include<stdio.h>
#include<conio.h>
main()
{
    char ch1[]={'A','J','C','F','M'};
    char ch2[]={'B','E','T','L','H'};
    char ch3[3];
    int x,y=4;
    for(x=0;x<=4;x++)
    {
        if(ch2[y]>ch1[x]) ch3[x]=ch1[x]+1;
        y--;
        printf("%c \n",ch3[x]);
    }
    getch();
}
