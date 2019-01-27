#include<stdio.h>
#include<string.h>

    int x[10005],chec[10005],checkk[10005];
main()
{
    int n,k,a,i,j,check,range,high=0,imax,b;
    int last=0;
    scanf("%d%d%d",&n,&k,&a);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
        j=last+1;
        for(b=last+x[i];j<b+1;j++)
        {
            checkk[j]=i;
            last = j;
            //printf("%d",last);
        }
    }
    range = a*(k-1);
    //for(i=1;i<=last;i++)printf("%d %d\n",i,checkk[i]);
    for(i=1;i<=last;i++)
    {
        check =0;
        //printf("%d ",i);
        for(j=1;j<=last;j++)chec[checkk[j]]=1;
        for(j=i;j<=i+range && j<=last;j+=a)
        {
            //printf("%d ",chec[checkk[j]]);
            if(chec[checkk[j]]==1)
            {
                chec[checkk[j]]=0;
                check++;
                //printf("%d",check);
            }
        }
        //printf("\n");
        if(high<check)
        {
            high = check;
            imax = i;
        }
        else if(high==check)
        {
            if(imax>i)
            {
                high = check;
                imax = i;
            }
        }
    }
    printf("%d %d",imax,high);
}
