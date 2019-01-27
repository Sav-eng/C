#include<stdio.h>
main()
{
    int n,check=0,i,j,a[10],sum=0,max=-99999,checkr=0;
    char ans[100][100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
        if(max<a[i])max = a[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<a[i];j++)
        {
            //if(j==0)ans[j+check][max/2]= '*';
            ans[checkr+max-1][check]= '*';
            ans[max-checkr-1][check]= '*';
            check++;
            checkr++;
        }
        checkr=0;
        check++;
    }
    for(i=0;i<2*max-1;i++)
    {
        for(j=0;j<sum+(n-1)*4;j++)
        {
            printf("%c",ans[i][j]);
        }
        printf("\n");
    }
}
