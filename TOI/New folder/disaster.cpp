#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,order;
};
int n;
vector<node>from[301];
map<char,int>mp;
bool tab[301];
int e=-1;
map<int,char>mp2;
void dfs(int x,int y)
{
    if(y==n)return ;
    else
    {
        int i;
        for(i=0;i<from[x].size();i++)
        {
            //printf("%c---->%c\n",mp2[x],mp2[from[x][i].x]);
            if(tab[from[x][i].order]==0)
            {
                if(from[x][i].x==e && y==n-1)
                {
                    tab[from[x][i].order]=1;
                    printf("%c ",mp2[from[x][i].x]);
                    dfs(from[x][i].x,y+1);
                }
                else if(from[x][i].x!=e)
                {
                    tab[from[x][i].order]=1;
                    printf("%c ",mp2[from[x][i].x]);
                    dfs(from[x][i].x,y+1);
                }

            }
        }
    }
    //printf("a");
}
int mem[301];
main()
{
    int i;
    char a,b;
    int check=0,m=0,check2=1;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf(" %c %c",&a,&b);
        if(mp.find(a)==mp.end())
        {
            mp2[check] = a;
            mp[a] = check++;

        }
        if(mp.find(b)==mp.end())
        {
            mp2[check]=b;
            mp[b] = check++;
        }
        from[mp[a]].push_back({mp[b],i});
        from[mp[b]].push_back({mp[a],i});
        mem[mp[a]]++;
        mem[mp[b]]++;
    }
    //printf("%d",check);
    m=check;
    int s=0;
    for(i=0;i<m;i++)
    {
        //printf("%d ",mem[i]);
        if(mem[i]%2!=0)
        {
            if(check2){s =i;check2=0;}
            else if(mem[i]==1)e = i;
            else
            {
                e=i;
            }
        }
    }
    //printf("e = %c\n",mp2[e]);
    if(s==0)
    {
        printf("%c ",mp2[1]);
        dfs(1,0);
    }
    else if(s!=0)
    {
        printf("%c ",mp2[s]);
        dfs(s,0);
    }

}
