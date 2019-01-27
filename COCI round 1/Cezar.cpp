#include<bits/stdc++.h>
using namespace std;
int mem[100];
main()
{
    int n,u,a,sum=0,Less=0,Greater=0,i,j;
    scanf("%d",&n);
    for(i=1;i<=11;i++)mem[i] = i==10?12:4;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        sum+=a;
        mem[a]--;
    }
    int t =  21-sum;
    for(i=1;i<11;i++)
    {
        if(i<=t)Less+=mem[i];
        else Greater+=mem[i];
    }
    if(Greater >= Less)printf("DOSTA");
    else printf("VUCI");
}
