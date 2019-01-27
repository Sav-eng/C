#include<bits/stdc++.h>
using namespace std;
int mem[101][101];
main()
{
    int n,m,i,j,k,a,b,time=0;
    while(scanf("%d",&m)!=EOF)
    {
        n=0;
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            mem[a][b] = 1;
            n = max(n,max(a,b));
        }
        n++;
        for(k=0;k<n;k++)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    mem[i][j] += mem[i][k]*mem[k][j];
                }
            }
        }
        for(k=0;k<n;k++)
        {
            if(mem[k][k]!=0)
            {
                for(i=0;i<n;i++)
                {
                    for(j=0;j<n;j++)
                    {
                        if(mem[i][k] !=0 && mem[k][j] !=0)mem[i][j] = -1;
                    }
                }
            }

        }
        printf("matrix for city %d\n",time++);
        for(i=0;i<n;i++)
        {
            printf("%d",mem[i][0]);
            for(j=1;j<n;j++)
            {
                printf(" %d",mem[i][j]);
            }
            printf("\n");
        }
        for(i=0;i<n;i++)for(j=0;j<n;j++)mem[i][j] = 0;
    }
}
