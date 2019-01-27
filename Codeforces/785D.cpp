#include<bits/stdc++.h>
using namespace std;
int n,bef,aft;
int mem[200005][5];
char a[200005];
int f(int x,int y)
{
    if(x==n)
    {
        //printf("bef = %d aft = %d\n",bef,aft);
        if(bef==aft)return 1;
        else return 0;
    }
    else
    {
        if(mem[x][y]==-1)
        {
            mem[x][y] = f(x+1,y);
            if(y==0)
            {
                if(a[x]=='(')
                {
                    bef++;
                    mem[x][y] += f(x+1,y);
                    bef--;
                }
                else
                {
                    aft++;
                    mem[x][y] += f(x+1,1);
                    aft--;
                }
            }
            else
            {
                if(a[x]==')')
                {
                    aft++;
                    mem[x][y] += f(x+1,1);
                    aft--;
                }
            }
        }
        return mem[x][y];
    }
}
main()
{
    int i;
    scanf("%s",a);
    n = strlen(a);
    for(i=0;i<200005;i++){mem[i][0] = -1; mem[i][1] = -1;}
    printf("%d",f(0,0)-1);
}
