#include<bits/stdc++.h>
using namespace std;
int tab[3][3];
int f(int l,int r)
{
    if(l-r==1)return tab[l][r]
    else
    {

    }
}
main()
{
    int time = 20;
    tab[0][0]=2;tab[1][2]=1;
    tab[0][1]=1;tab[2][0]=1;
    tab[0][2]=0;tab[2][1]=2;
    tab[1][0]=2;tab[2][2]=1;
    tab[1][1]=1;

    while(time--)
    {
        scanf("%d %s",&n,&a);
        memset(mem,0,sizeof(mem));
        printf("%d",f(0,n-1));
    }
}

