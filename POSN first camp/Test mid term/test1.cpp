#include<stdio.h>
main()
{
    int x,y,m,z;
    m = 2;
    z = 1;
    for(x=3;x<=10;x++)
    {
        for(y=0;y<=10;y=y+2)
            if((x+y)%3==0)
        {
            m++;
            if((y+m)%3==0)
                printf("Output = %d\n",m);
        }
        m=m+1;
    }
}
