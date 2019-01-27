#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
int sum[15];
string ta,tb;
long long f(string x,int y)
{
    int i;
    long long ten =1,t = 0;
    if(y==x.size())return 0;
    //if(x[y]==0)return f(x,y+1);
    if(y==0)
    {
        for(i=1;i<x.size();i++)
        {
            t += (x[i]-'0')*(x[y]-'0'+1);
        }
        t += sum[x[y]-'0'];
        return t+f(x,y+1);
    }
    else
    {
        for(i=1;i<y;i++)
        {
            ten *=10;
        }
        for(i=y+1;i<x.size();i++)
        {
            t += ten*10*(x[y]-'0')*(x[i]-'0');
        }
        t += 45*ten*(x[y]-'0')*y;
        t+= (sum[x[y]-'0'-1])*10*ten;
        //printf("%d",t);
        return t + f(x,y+1);
    }
}
long long a,b;
main()
{
    //freopen("test.txt","w",stdout);
    int i,t;

    for(i=1;i<=9;i++)
    {
        t = i;
        sum[i] = sum[i-1];
        while(t>0)
        {
            sum[i] +=t%10;
            t/=10;
        }
        //printf("sum[%d] = %d\n",i,sum[i]);
    }
    while(scanf("%lld%lld",&a,&b) && a>0 && b>0)
    {
        ta.clear();
        tb.clear();
        a--;
        t= a;
        while(t>0)
        {
            ta += t%10+'0';
            t/=10;
        }
        t= b;
        while(t>0)
        {
            tb +=t%10+'0';
            t/=10;
        }
        //printf("%d %d",f(ta,0),f(tb,0));
        printf("%lld\n",(long long)(f(tb,0)-f(ta,0)));
    }
}
