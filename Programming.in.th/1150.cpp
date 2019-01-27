#include<bits/stdc++.h>
using namespace std;
bool mem[2][60001];
bool flag;
main()
{
    int n,i,j,x,a,ans=30000;
    scanf("%d",&n);
    mem[0][30000]=1;
    flag = 1;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        for(j=0;j<=60000;j++)mem[flag][j] = (j==a+30000)?1:0;
        for(j=0;j<=60000;j++)
        {
            x = a+j;
            if(x<0)x+=60001;
            else if(x>60000)x-=60001;
            mem[flag][j] |= mem[!flag][j];
            mem[flag][x] |= mem[!flag][j];
            //if(mem[flag][j])printf("(%d)%d NC\n",flag,j);
            //if(mem[flag][x])printf("(%d)%d C from %d\n",flag,x,j);
            if(i==n-1)
            {
                if(mem[flag][x])ans = max(ans,x);
                if(mem[flag][j])ans = max(ans,j);
                //if(ans==x || ans ==j)printf("%d\n",ans);
            }
        }
        flag = !flag;
    }
    printf("%d",ans-30000);
}
/*
5
10 21 -31 17 -29999

*/
