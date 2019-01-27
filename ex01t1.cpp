#include<bits/stdc++.h>
using namespace std;
int cx[] = {0,0,1,1};
int cy[] = {0,1,0,1};
void f(int X,int Y,int A,int B,int N)
{
    int C = (A-X)/N +((B-Y)*2)/N;
    if(N==1)
    {
        printf("%d %d %d\n",C,X,Y);
    }
    else
    {
        int i;
        int x,y,a,b;
        x = X+N-1;
        y = Y+N-1;
        printf("%d %d %d\n",C,x,y);
        for(i=0;i<4;i++)
        {
            a = (i==C)?A:x+cx[i];
            b = (i==C)?B:y+cy[i];
            f(X+cx[i]*N,Y+cy[i]*N,a,b,N>>1);
        }
    }

}
main()
{
    int n,x,y;
    scanf("%d%d%d",&n,&x,&y);
    f(0,0,y,x,n>>1);
}
