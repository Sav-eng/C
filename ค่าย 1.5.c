#include<stdio.h>
main()
{
    char a[5][5]={"ABCD","BCDE","CDEF","DEFG"},t[255],b;
    int n,i,j;
    scanf("%s",&t);
    n = strlen(t);
    for(i=0;i<n/2;i+=2)
    {
        if(t[i]=='L')
        {
            b = a[0][t[i+1]];
            a[0][t[i+1]] = a[1][t[i+1]];
            a[1][t[i+1]] = a[2][t[i+1]];
            a[2][t[i+1]] = a[3][t[i+1]];
            a[3][t[i+1]] = b;
        }
        if(t[i]=='R')
        {
            b = a[3][t[i+1]];
            a[3][t[i+1]] = a[2][t[i+1]];
            a[2][t[i+1]] = a[1][t[i+1]];
            a[1][t[i+1]] = a[0][t[i+1]];
            a[0][t[i+1]] = b;
        }
        if(t[i]=='U')
        {
            b = a[t[i+1]][0];
            a[t[i+1]][0] = a[t[i+1]][1];
            a[t[i+1]][1] = a[t[i+1]][2];
            a[t[i+1]][2] = a[t[i+1]][3];
            a[t[i+1]][3] = b;
        }
        if(t[i]=='D')
        {
            b = a[t[i+1]][3];
            a[t[i+1]][3] = a[t[i+1]][2];
            a[t[i+1]][2] = a[t[i+1]][1];
            a[t[i+1]][1] = a[t[i+1]][0];
            a[t[i+1]][0] = b;
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
             printf("%c",a[i][j]);

        }
        printf("\n");
    }

}
