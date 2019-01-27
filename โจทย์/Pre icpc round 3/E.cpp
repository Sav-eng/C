#include<bits/stdc++.h>
using namespace std;
long long mem[1051][1051];
main()
{
    int n,i,j,check2;
    long long check;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&mem[0][i]);
    }
    if(n==1)
    {
        printf("%d",mem[0][0]);
        return 0;
    }
    for(i=1;i<n;i++)
    {
        check2 = 0;
        for(j=i;j<n;j++)
        {
            mem[i][j-i] = mem[i-1][j-i+1]-mem[i-1][j-i];
            if(j==i)check = mem[i][j-i];
            if(check!=mem[i][j-1-i])check2=1;
        }
        if(!check2)break;
    }
    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%4d",mem[i][j]);
        }
        printf("\n");
    }*/
    if(check2)i--;
    j-=i;
    //printf("i = %d j = %d check = %d\n",i,j,check);
    mem[i][j]=check;
    while(i>0)
    {
        i--,j++;
        //printf("i = %d j = %d\n",i,j);
        mem[i][j] = mem[i][j-1]+mem[i+1][j-1];
        //printf("%d ",mem[i][j]);
    }
    printf("%lld",mem[i][j]);
}

/*

4
0 12 30 53 80

14
1 3 5 7 9 11 13 15 17 19 21 23 25 27

2
-1000000000 0

*/
