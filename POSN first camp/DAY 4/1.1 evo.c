#include<stdio.h>
int i,j,a[2000000],sum=0,n,check=0;
main()
{

    scanf("%d",&n);
    for(i=2;i<=n;i++)
    {
        a[i] = i;
    }
    i = 2;
    while(i!=n)
    {

        for(j=i+1;j<n;j++)
        {
            if(a[i]==0)break;

            if(a[j] % a[i]==0)a[j]=0;
        }
        if(a[i]!=0)
        {
            //printf("%d ",a[i]);
            check++;
        }
        i++;
    }
    for(i=2;i<n;i++)
    {
        if(n%i!=0)
        {
            printf("%d",n);
            check++;
            break;
        }
        else
        break;

    }
    printf("%d",check);

}

