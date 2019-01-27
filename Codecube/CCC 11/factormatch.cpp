#include<bits/stdc++.h>
using namespace std;
int mem[1000001];
int a[1000001];
int b[1000001];
int tab[1000001];
main()
{
    int i,j;
    for(i=1;i<=100000;i++)
    {
        for(j=1;j<sqrt(i);j++)
        {
            if(i%j==0)mem[i]+=2;
        }
        if(j*j==i)mem[i]++;

    }
    int n,m;
    int ans = 1e9;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        a[i] = mem[a[i]];
        //printf("%d ",a[i]);
    }
    //printf("\n");
    for(i=0;i<m;i++)
    {
        scanf("%d",&b[i]);
        b[i] = mem[b[i]];
        //printf("%d ",b[i]);
    }
    //printf("\n");
    j = 0;
    tab[0]=0;
    for(i=1;i<m;i++)
    {
        while(j>0 && b[i]!=b[j])j = tab[j-1];
        tab[i] = (b[i]==b[j])?++j:0;
    }
    j = 0;
    ans = -1;
    for(i=0;i<n;i++)
    {
        while(a[i]!=b[j] && j>0)j = tab[j-1];
        if(a[i]==b[j])
        {
            if(n-i>=m-j)ans = max(j,ans);
            j++;
        }
    }
    printf("%d",ans+1);
}
