#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y)
{
    if(x==0)return y;
    else if(y==0)return x;
    else return gcd(y,x%y);
}
main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d",gcd(a,b));
}
