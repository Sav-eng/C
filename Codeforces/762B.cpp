#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
string b;
struct node
{
    long long x;
    bool w;
    bool operator < (node a)const
    {
        return a.x>x;
    }
};
node mem[300005];
main()
{
    int n,m,k,t,cnt=0,i,a1,sum,cnt2=0,j,ans2=0;
    long long ans=0;
    scanf("%d%d%d%d",&n,&m,&k,&t);
    for(i=0;i<t;i++)
    {
        scanf("%lld",&mem[i].x);
        cin >> b;
        //mem[i].x = a1;
        if(b=="USB")mem[i].w = 0;
        else mem[i].w = 1;
    }
    sort(&mem[0],&mem[t]);
    i=0;
    for(i=0;i<t;i++)
    {
        if(mem[i].w==0 && n > 0)
        {
            ans += mem[i].x;
            ans2++;
            n--;
        }
        else if(mem[i].w == 1 && m > 0)
        {
            ans += mem[i].x;
            ans2++;
            m--;
        }
        else if(k > 0)
        {
            ans += mem[i].x;
            ans2++;
            k--;
        }

        //printf("%d ",ans);
    }
    printf("%d %lld",ans2,ans);
}
/*

0 1 1
4
5 USB
1 USB
4 PS/2
7 USB

*/
