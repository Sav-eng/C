#include<stdio.h>
struct bigint
{
    int len;
    int val[10005];
    bigint operator + (bigint a) const
    {
        int i;
        bigint t;
        for(i=0;i<10005;i++) t.val[i] = a.val[i] + val[i];
        for(i=0;i<10005;i++)
        {
            if(t.val[i]>=10)
            {
                t.val[i+1] += t.val[i]/10;
                t.val[i] %= 10;
            }
            if(t.val[i]!=0) t.len = i;
        }
        return t;
    }
    bigint(int x = 0)
    {
        int i;
        for(i=0;i<10005;i++) val[i] = 0;
        val[0] = x;
        len = 0;
    }
};
bigint mem[2][2];
main()
{
    int i,n,flag = 1;
    bigint t;
    scanf("%d",&n);
    mem[0][1] = bigint(1); mem[0][0] = bigint(1);
    for(i=mem[!flag][1].len;i>=0;i--)
    {
        printf("%d",mem[!flag][1].val[i]);
    }
    for(i=1;i<=n;i++)
    {
        mem[flag][0] = mem[!flag][1];
        mem[flag][1] = mem[!flag][1] + mem[!flag][0];
        flag = !flag;
    }

}
//fibo
