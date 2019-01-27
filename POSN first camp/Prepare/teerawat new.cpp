#include<stdio.h>
main()
{
    int n,nc=0,tall=1,i,j,k,ii=0,jj=0,check;
    char a[100][100]={{}},ac[100][100]={{}},ans[100][100]={{}};
    char count='A';
    scanf("%d",&n);
    if(n==1)printf("A");
    nc = n;
    while(nc>0)
    {
        nc = nc-tall;
        tall++;
    }
    tall-=2;
    //printf("%d\n",tall);
    //printf("%d\n",nc);
    a[0][tall]='*';
    for(i=tall;i>=0;i--)
    {
        if(i==tall)
        {
            for(j=tall+nc;j>=0;j--)
            {
                if(i%2!=0)
                {
                    a[i][tall+j]='*';
                }
                else if(i!=0)
                {
                    a[i][tall-j]='*';
                }
            }
        }
        else
        {
            for(j=i;j>=0;j--)
            {
                if(i%2!=0)
                {
                    a[i][tall+j]='*';
                }
                else if(i!=0)
                {
                    a[i][tall-j]='*';
                }
            }
        }
    }
    for(i=0;i<50;i++)
    {
        for(j=0;j<50;j++)
        {
            if(a[i][j]=='*')
            {
                if(i%2==0)
                {
                    ac[i][tall-j] = count;
                }
                else
                {
                    a[i][j] = count;
                }
                count++;
                if(count>'Z')count='A';
            }
        }
    }
    nc = -nc;
    for(i=0;i<=50;i++,ii++)
    {
        if(i%2==0)for(k=0;k<tall-i;k++)
        {
            ans[ii][jj]=' ';
            jj++;
        }
        if(i==tall && i%2==0)for(k=0;k<nc;k++)
        {
            ans[ii][jj]=' ';
            jj++;
        }
        for(j=0;j<50;j++)
        {
            if(i%2!=0)
            {
                ans[ii][jj] = a[i][j];
                jj++;
            }
            else
            {
                ans[ii][jj] = ac[i][j];
                jj++;
            }
        }
        jj=0;
    }
    k=0;
    check =0;
    for(i=0;check==0;i++)
    {

        for(j=0;j<50;j++)
        {
            if(ans[j][i]>='A'&&ans[j][i]<='Z')
            {
                check++;
                break;
            }
        }
    }
    i--;
    k = i;
    printf("%d %d\n",i,nc);
    for(i=0;i<50;i++)
    {
        for(j=k;j<50;j++)
        {
            printf("%c",ans[i][j]);
        }
        printf("\n");
    }
}
