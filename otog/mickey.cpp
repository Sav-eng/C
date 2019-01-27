#include<bits/stdc++.h>
using namespace std;
int mem[10][10];
main()
{
    int i,j;
    srand(time(NULL));
    for(i=1;i<=8;i++)
    {
        for(j=1;j<=8;j++)
        {
            if(i!=j)
            {
                int t = (rand()%8)+1;
                while(t==i || t==j || mem[i][j] == mem[j][i])mem[i][j] = t = (rand()%8)+1;
                printf("%d %d %d\n",i,j,t);
            }
        }
    }
}
