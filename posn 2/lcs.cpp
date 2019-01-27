#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int na,nb;
char a[100],b[100];
int mem[100][100];
int f(int x,int y)
{
    if(x>=na || y>=nb)return 0;
    if(mem[x][y]!=0)return mem[x][y];
    mem[x][y] = max(mem[x][y],f(x+1,y));
    mem[x][y] = max(mem[x][y],f(x,y+1));
    if(a[x]==b[y])
    {
        mem[x][y] = 1 + f(x+1,y+1);
    }
    return mem[x][y];
}
main()
{
    gets(a);
    gets(b);
    na = strlen(a);
    nb = strlen(b);
    //printf("%d %d",na,nb);
    printf("%d",f(0,0));
}
/*
globalchange
localvariable
*/
