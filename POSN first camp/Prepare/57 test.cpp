#include<stdio.h>
main()
{
    char ch='A';
    int a,b,i,max,j,check;
    char x[100][100];
    scanf("%d %d",&a,&b);
    if(a>b)max = a;
    else max = b;
    ch = ch+a-1;
    for(i=1;i<=2*a-1;i++)
    {
            x[i][i]=ch;
            x[a*2-i][i] =ch;
            if(i>=a)ch++;
            else ch--;
    }
    check = i;
    for(i=1;i<=2*b-1;i++)
    {
            x[i][i+check-1]='*';
            x[b*2-i][i+check-1] ='*';
    }
    for(i=1;i<=max*2-1;i++)
    {
        for(j=1;j<=(2*a)+(2*b);j++)
        {
            printf("%c",x[i][j]);
        }
        printf("\n");
    }
}
