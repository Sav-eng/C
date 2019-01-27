#include<stdio.h>
char a[200000];
main()
{
    int n,i;
    scanf("%d",&n);
    scanf(" %s",a);
    a[-1]='0';
    for(i=0;i<n;i++)
    {
        if(a[i]=='X')
        {
            if(a[i-1]!='B' && a[i+1]!='B')
            {
                a[i]='B';
            }
            if(a[i-1]!='W' && a[i+1]!='W')
            {
                a[i]='W';
            }
            if(a[i-1]=='B' && a[i+1]=='W')
            {
                a[i] ='G';
            }
            if(a[i-1]=='W' && a[i+1]=='B')
            {
                a[i]='G';
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%c",a[i]);
    }
}
/*
10
WXXWXXWXXB
*/
