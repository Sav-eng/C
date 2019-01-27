#include<stdio.h>
main()
{
    struct a
    {
        int num;
        char ch;
    };
    struct a x;
    x.num = 1;
    x.ch = 'A';
    int i,check=0,count = 0;
    for(i=0;i<15;count++,i++)
    {
        if(count>=3)count = 0;
        printf("%d",x.num+check);
        if(i%3-2==0)check++;
        printf("%c\n",x.ch+count);

    }
}
