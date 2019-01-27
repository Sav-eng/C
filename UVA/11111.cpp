#include<bits/stdc++.h>
using namespace std;
string x;
int a[1000001];
int s[1000001];
int mem[1000001];
int TOS;
void push(int x)
{
    TOS++;
    s[TOS] = x;
}
bool pop()
{
    mem[TOS-1] += s[TOS];
    if(mem[TOS-1]>=s[TOS-1] && TOS>0)return true;
    mem[TOS]=0;
    TOS--;
    return false;
}
int top()
{
    return s[TOS];
}
main()
{
    int i,j,k,cnt=0,n;
    while(getline(cin,x))
    {
        memset(mem,0,sizeof(mem));
        memset(s,0,sizeof(s));
        memset(a,0,sizeof(a));
        j = 0;
        n = x.size();
        cnt=0;
        for(i=0;i<n;i++)
        {
            if(x[i]==' ')
            {
                for(k=j;k<i;k++)
                {
                    a[cnt] *=10;
                    if(x[k]!='-')a[cnt] += x[k]-'0';
                }
                if(x[j]=='-')a[cnt]*=-1;
                cnt++;
                j = i+1;
            }
        }
        for(k=j;k<n;k++)
        {
            a[cnt] *=10;
            if(x[k]!='-')a[cnt] += x[k]-'0';
        }
        cnt++;
        TOS = -1;
        bool check=0;
        for(i=0;i<cnt;i++)
        {
            //for(j=0;j<=TOS;j++)printf("%d ",s[j]);
            //printf("TOS = %d(%d)\n",TOS,mem[TOS]);
            if(TOS==-1)
            {
                push(-a[i]);
            }
            else
            {
                if(top()==a[i])
                {
                    if(pop())
                    {
                        printf(":-( Try again.\n");
                        check=1;
                        break;
                    }
                }
                else push(-a[i]);
            }
        }
        if(!check && TOS==-1)printf(":-) Matrioshka!\n");
        else if(!check)printf(":-( Try again.\n");
    }
}
