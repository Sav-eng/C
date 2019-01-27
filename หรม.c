#include<stdio.h>
int H(int n, int m)
{
    int temp,i,a=1;

    if(m>n)
    {
        temp = m;
        m =n;
        n = temp;
    }
    for(i=1;i<n;i++)
    {
        if(n%i == 0 && m%i == 0)a = i;
    }
    return a;
}
main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    printf("%d",H(n,m));
}
