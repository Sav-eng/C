#include<bits/stdc++.h>
using namespace std;
struct bigint
{
    int len,val[51];
    bigint operator +(bigint a)const
    {
        int i;
        bigint t;
        for(i=0;i<50;i++)t.val[i]=a.val[i]+val[i];
        for(i=0;i<50;i++)
        {
            if(t.val[i]>=10)t.val[i+1] += t.val[i]/10,t.val[i]%=10;
            if(t.val[i]!=0)t.len=i;
        }
        return t;
    }
    bigint(int x=0)
    {
        int i;
        for(i=0;i<50;i++)val[i] = 0;
        val[0] = x;
        len = 0;
    }
};
bigint mem[201][201];
main()
{
    int i,j,time,n,m,sum,a,k;
    mem[0][0] = bigint(1);
    for(i=1;i<=200;i++)//block that not count in code
    {
        mem[i][0]= bigint(1);
        for(j=1;j<=i;j++)//m // piece of code
        {
            mem[i][j] = mem[i][j]+mem[i-1][j-1]+mem[i-1][j];
            /*printf("mem[%d][%d] = ",i,j);
            for(k=mem[i][j].len;k>=0;k--)
            {
                printf("%d",mem[i][j].val[k]);
            }
            printf("\n");*/
        }
    }
    scanf("%d",&time);
    while(time--)
    {
        scanf("%d%d",&n,&m);
        sum = n;
        for(i=0;i<m;i++)
        {
            scanf("%d",&a);
            sum-=a;
        }
        sum++;
        for(i=mem[sum][m].len;i>=0;i--)
        {
            printf("%d",mem[sum][m].val[i]);
        }
        cout << endl;
    }
}
