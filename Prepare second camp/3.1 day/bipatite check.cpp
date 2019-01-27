#include<stdio.h>
#include<vector>
using namespace std;
int ch[100]={};
bool ah = 0;
int n;
int a[100],b[100];
vector<int>vec[100];
void check(int x,bool c)
{
    int i;
    ch[x] = c;
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
    scanf("%d %d",&n,&k);
    for(i=0;i<k;i++)
    {
        scanf("%d %d",&a[i],&b[i]);
    }
    for(i=0;i<n;i++)
    {
        ch[i] == -1;
    }
    for(i=0;i<n;i++)
    {
        while(i==a[j])
        {
            vec[i].push_back(b[j]);
            j++;
        }
    }
    for(i=0;i<n;i++) if(ch[i]==-1) check(i,0);
    if(ah==1)printf("No");
    else printf("Yes");
}
