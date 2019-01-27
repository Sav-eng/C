#include<stdio.h>
#include<string.h>
#define mod 1000000007
int n;
int mem[200005][10];
char s[200005];
int f(int x,int val)
{
    if(x==n) return val==0;
    if(mem[x][val]==-1)
    {
        mem[x][val] = (f(x+1,(val*10+s[x]-'0')%8) + f(x+1,val))%mod;
    }
    return mem[x][val];
}
int main()
{
    int i,a,b,c,x,ans;
    scanf("%d %s",&n,s);
    memset(mem,-1,sizeof(mem));
    printf("%d",(f(0,0)-1+mod)%mod);
}
