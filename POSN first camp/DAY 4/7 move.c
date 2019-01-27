#include<stdio.h>
main()
{
    int b,i=0,s[10]={1,2,3,4,5,6,7,8,9,0},count = 0;
    char a;
    scanf("%c %d",&a,&b);
    if(a=='R')
    {
        while(i<10)
        {
            if(10-b+i>=10)printf("%d",s[i-b]);
            else printf("%d",s[10-b+i]);
            i++;
        }
    }
    if(a=='L')
    {
        while(i<10)
        {
            if(b+i>=10)
            {
                printf("%d",s[count]);
                count++;
            }
            else
            printf("%d",s[b+i]);
            i++;
        }
    }
}
