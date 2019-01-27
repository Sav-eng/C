#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
int mem[101][101];
string s;
int f(int l,int r)
{
    if(l==r)return 1;
    else if(!mem[l][r])
    {
        int i,j,k,len;
        mem[l][r] = inf;
        for(i=l;i<r;i++)
        {
            mem[l][r] = min(mem[l][r],f(l,i)+f(i+1,r));
        }
        len = r-l+1;
        for(i=1;i<=len;i++)
        {
            if(len%i==0)
            {
                for(j=0,k=l;k<=r;k++)
                {
                    if(s[k]!=s[j+l])break;
                    j++;
                    if(j==i)j=0;
                }
                if(k==r+1 && r!=l+i-1)mem[l][r] = min(mem[l][r],f(l,l+i-1));
            }
        }
        //printf("mem[%d][%d] = %d\n",l,r,mem[l][r]);
    }
    return mem[l][r];

}
main()
{
    while(cin >> s)
    {
        if(s[0]=='*')break;
        memset(mem,0,sizeof(mem));
        printf("%d\n",f(0,s.size()-1));
    }
}
