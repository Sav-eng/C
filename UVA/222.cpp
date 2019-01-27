#include<bits/stdc++.h>
using namespace std;
int a,b;
int f(int x,int y)
{
    if(x==n)return 0;
    else if(!mem[x][y])
    {

    }
    return mem[x][y];
}
main()
{
    int check=1,i,d,c;
    while(scanf("%d",&e)!=EOF)
    {
        scanf("%lf%lf%lf%d",&a,&b,&c,&n);
        for(i=0;i<n;i++)
        {
            scanf("%lf%lf",&x[i],&y[i]);
        }
        x[n]=e;
        printf("Data set #%d\n",check++);
        printf("minimum cost = $%d\n",f(0,a));
    }
}
