#include<stdio.h>
#include<string.h>
main()
{
    int check,count=0,i=0;
    char a[20];
    gets(a);
    char ans[1];
    while(a[i]!='\0')
    {
        if(i==0)
        {
            ans[i+count] = a[i];
            check = a[i];
        }
        else
        {
            if(a[i]==check)
            {
                ans[i+count]='X';
                count++;
                ans[i+count]=a[i];
            }
            else
            {
                check = a[i];
                ans[i+count] = a[i];
            }
        }
        i++;
    }
    puts(ans);
}
