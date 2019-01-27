#include<stdio.h>
main()
{
    int x,y,count=1;
    int sum = 0;
    for(x=1;x<=10;x++)
    {
        sum = sum + y;
        for(y=4;y<=10;y++)
        {
            sum = x+y;
            if(((sum+x)%8)==0)
               {
                   count++;
                   if((count%3)==0)
                    printf("Output = %d\n",sum);
               }

        }
        sum = sum-x-y;
    }
}

