#include<stdio.h>
#include<algorithm>
using namespace std;
int abs(int x)
{
    if(x>0)return x;
    else return -x;
}
main()
{
    int a,b,y,z,p1,p2;
    int ans=0;
    scanf("%d%d",&a,&b);
    scanf("%d%d",&y,&z);
    if(abs(a-y)>abs(y-a))
    {
        p1 = abs(y-a);
    }
    else p1 = abs(a-y);
    if(abs(24-a+y)>abs(24-y+a))
    {
        p2 = abs(24-y+a);
    }
    else p2 = abs(24-a+y);
    ans += min(p1,p2);

    if(abs(b-z)>abs(z-b))
    {
        p1 = abs(z-b);
    }
    else p1 = abs(b-z);
    if(abs(60-b+z)>abs(60-z+b))
    {
        p2 = abs(60-z+b);
    }
    else p2 = abs(60-b+z);
    ans += min(p1,p2);
    printf("%d",ans);
}

/*
13 13
23 40
*/
