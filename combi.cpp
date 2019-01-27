#include<stdio.h>
int n,a[100]={};
void combi(int i)
{
    int j;
    if(i==n)
    {
        for(j=0;j<n;j++)
        {
            if(a[j]==1)
                printf("%d",j+1);
        }
        printf("\n");
    }
    else
    {
        a[i]=0;
        combi(i+1);
        a[i]=1;
        combi(i+1);
    }
}
main()
{
    scanf("%d",&n);
    combi(0);
}
