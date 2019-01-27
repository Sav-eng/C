#include<bits/stdc++.h>
using namespace std;
int a[100001];
int f(int x,int y)
{
    if(x==0)
    {
        int i;
        for(i=0;i<y;i++)
        {
            printf("%c%c\n",a[i],a[i]);
        }
        printf("E\n");
    }
    else
    {
        a[y] = '-';
        f(x-1,y+1);
        if(x>=2)
        {
            a[y] = '|';
            f(x-2,y+1);
        }

    }
}
main()
{
    int n;
    scanf("%d",&n);
    f(n,0);
}

