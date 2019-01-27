#include<stdio.h>
#include<algorithm>
using namespace std;
double a[100][100];
double mem[2100000];
int n;
bool checkval[2100000];
double recur(int x,int bit)
{
    int i;
    if(x==n)
    {
        return 1;
    }
    else
    {
        if(checkval[bit])return mem[bit];
        for(i=0;i<n;i++)
        {
            int check;
            check = 1<<(n-i) & bit;
            if(!check)mem[bit] = min((a[x][i]*recur(x+1,(bit | (1<<(n-i))))),mem[bit]);
        }
        checkval[bit]=1;
        return mem[bit];
    }
}
main()
{
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%lf",&a[i][j]);
            a[i][j]/=100;
        }
    }
    double temp,ans=0;
    for(i=0;i<n;i++)
    {
        temp = recur(0,1<<i);
        if(ans<temp)ans = temp;
    }

    printf("%lf",ans*100);
}
