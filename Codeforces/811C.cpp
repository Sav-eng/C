#include<bits/stdc++.h>
using namespace std;
int mem[5005];
int a[5005];
int _max[5005];
int _min[5005];
int head[5005];
int s[5005];
int val[5005];
int sum[5005];
int TOS;
int push(int x)
{
    TOS++;
    s[TOS]=x;
    val[TOS]=x;
}
int top()
{
    return s[TOS];
}
void pop()
{
    val[TOS-1] ^= val[TOS];
    TOS--;
}
void unionset(int x,int y)
{
    head[y] = x;
    _max[x] = max(_max[x],_max[y]);
}
int findhead(int x)
{
    if(x==head[x])return x;
    return head[x] = findhead(head[x]);
}
main()
{
    int n,i,j,x;
    scanf("%d",&n);
    for(i=1;i<=5000;i++)
    {
        _min[i] = n+1;
        head[i] = i;
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        _min[a[i]] = min(i,_min[a[i]]);
        _max[a[i]] = max(i,_max[a[i]]);
    }
    for(i=1;i<=n;i++)
    {
        x = findhead(a[i]);
        if(_min[x]==i)push(x);
        if(i!=_min[x] || i ==_max[x])
        {
            while(TOS!=0 && top()!=x)
            {
                unionset(x,top());
                pop();
            }
            if(i==_max[x])
            {
                sum[x] = val[TOS];
                pop();
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        x = findhead(a[i]);
        //printf("sum[%d] = %d\n",x,sum[x]);
        if(i==_max[x])mem[i] = max(mem[i-1],mem[_min[x]-1]+sum[x]);
        else mem[i] = mem[i-1];
    }
    printf("%d",mem[n]);
}
