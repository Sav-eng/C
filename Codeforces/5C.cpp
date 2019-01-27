#include<bits/stdc++.h>
using namespace std;
string s;
char ST[1000001];
int mem[1000001];
int mem2[1000001];
int mem3[1000001];
int TOS=0;
int _max=0;
int ans;
char top()
{
    return ST[TOS];
}
void push(int x,int y)
{
    TOS++;
    ST[TOS]=x;
    mem2[TOS]=y;
}
void pop()
{
    mem[TOS-1] += mem[TOS]+2;
    int now = mem2[TOS];
    mem3[now] += mem[TOS-1];
    if(_max<mem3[now])
    {
        _max = mem3[now];
        ans =0;
    }
    if(_max==mem3[now])ans++;
    mem[TOS]=0;
    TOS--;
}
main()
{
    int n,i,j;
    cin >> s;
    n = s.size();
    TOS = 0;
    push(s[0],1);
    for(i=1;i<n;i++)
    {
        if(s[i]==')' && top() == '(')pop();
        else push(s[i],i+1);
        for(j=0;j<=14;j++)printf("%d ",mem[j]);
        printf("\t");
        for(j=0;j<=14;j++)printf("%d ",mem3[j]);
        printf("\tTOS = %d ans = %d\n",TOS,ans);
    }
    printf("%d %d",_max,(_max==0)?1:ans);
}
/*

(()()

((((()(((

*/
