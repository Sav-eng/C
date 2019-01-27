#include<stdio.h>
#include<vector>
using namespace std;
int ch[205]={};
bool ah = 0;
int n,c0,c1;
int a[10005],b[10005];
vector<int>vec[205];
void check(int x,bool c)
{
    int i;
    ch[x]=c;
    if(c==0) c0++;
    else c1++;
    //printf("\nch[%d] = %d\n",x,ch[x]);
    for(i=0;i<vec[x].size();i++)
    {
        if(ch[vec[x][i]]==c)
        {
            ah = 1;
            return;
        }
        else if(ch[vec[x][i]]==-1)
        {
            check(vec[x][i],!c);
        }
    }
}
main()
{
    int k,i,j;
    int t,ti,ans[1000];
    scanf("%d",&t);
    for(ti=0;ti<t;ti++)
    {
        ah = 0;
        ans[ti] = 0;
        scanf("%d %d",&n,&k);
        for(i=0;i<n;i++)
        {
            vec[i].clear();
        }
        for(i=0;i<k;i++)
        {
            scanf("%d %d",&a[i],&b[i]);
            vec[a[i]].push_back(b[i]);
            vec[b[i]].push_back(a[i]);
        }
        for(i=0;i<n;i++)
        {
            ch[i] = -1;
        }
        for(i=0;i<n;i++)
        {
            if(ch[i]==-1)
            {
                c0 = 0;
                c1 = 0;
                check(i,0);
                ans[ti] += max(1,min(c0,c1));
            }
        }
        if(ah==1)ans[ti] = -1;
    }
    for(i=0;i<t;i++)
    {
        printf("%d\n",ans[i]);
    }
}
