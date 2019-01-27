#include<bits/stdc++.h>
using namespace std;
int tab[1000001];
main()
{
    int x,y,t,j,i,check,check2=0;
    for(i=2;i<=1000;i++)
    {
        t = i*i;
        check = 0;
        for(j=2;j<i;j++)
        {
            if(i%j==0)check++;
            //printf("%d %d\n",i,j);
        }
        if(check==0)tab[t] = 1;
    }
    scanf("%d%d",&x,&y);
    x = (x==1)?2:x;
    for(i=x;i<=y;i++)
    {
        if(tab[i]==1)
        {
            printf("%d ",i);
            check2 = 1;
        }
    }
    if(!check2)printf("-1");
}
