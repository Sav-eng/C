#include<stdio.h>
main()
{
    int n,t,r,i,j,k,a[1000],mon=0,b[1000];
    int check=0;
    int ib,jb;
    scanf("%d %d %d",&n,&t,&r);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i]!=-1 && b[j]!= -1)
                {
                    if(a[i]+b[j]==t)
                    {
                        a[i]==-1;
                        b[j]==-1;
                    }
                    else if(mon<a[i]+b[j])
                    {
                        ib = i;
                        jb = j;
                        mon = a[i]+b[j];

                    }
                }
            }
        }
        if(mon>t)check += mon-t;
        a[ib]=-1;
        b[jb]=-1;
        printf("%d ",check);
    }
    printf("%d",check);
}
