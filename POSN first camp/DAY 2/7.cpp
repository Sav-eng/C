#include<stdio.h>
main()
{
    int i,j,a[300000],sum=0,n,check=0;
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
            printf("%d ",a[i]);
            sum = sum+a[i];
            check++;
        }
        i++;
    }
    printf("\n%d\n ",sum);
    printf("%d",check);

}
