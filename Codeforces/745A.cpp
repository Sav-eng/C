#include<stdio.h>
#include<string.h>
using namespace std;
char x[1000];
main()
{
    int i,j,start;
    gets(x);
    for(i=1;i<strlen(x);i++)
    {
        j=0;
        if(x[i]==x[j])start = i;
        while(x[i]==x[j])
        {
            i++;
            j++;
        }
    }
    //printf("%d %d\n",j,i-start);
    if(j==i-start-1)printf("%d",strlen(x)-j);
    else printf("%d",i);
}
/*

abcabc

*/
