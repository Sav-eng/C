#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
string a,Template;
int mem[100001][10];
int trac[100001][10];
int n;
int f(int x,int y)
{
    if(x==n && y!=8)return inf;
    else if(y==8)return 0;
    else if(!mem[x][y])
    {
        mem[x][y] = inf;
        if(y==0)
        {
            if(a[x]==Template[y])
            {
                trac[x][y] = -1;
                mem[x][y] = f(x+1,y+1)+1;
            }
            if(mem[x][y]>f(x+1,y))
            {
                mem[x][y] = f(x+1,y);
                trac[x][y] = x+1;
            }
        }
        else
        {
            if(a[x]==Template[y])mem[x][y] = f(x+1,y+1)+1;
            else mem[x][y] = f(x+1,y)+1;
        }
        //printf("mem[%d][%d] = %d\n",x,y,mem[x][y]);
    }
    return mem[x][y];
}
main()
{
    Template = "codecube";
    cin >> a;
    n = a.size();
    int _min = f(0,0);
    if(_min>=inf)
    {
        printf("-1");
        return 0;
    }
    int i;
    //for(i=0;i<n;i++)printf("%d ",trac[i][0]);
    int t = 0;
    for(i=0;i<n;i++)if(trac[i][0]==-1)break;
    int p = 0;
    int start = i;
    for(i=start;i<n;i++)
    {
        if(Template[p]==a[i])p++;
        if(p==8)break;
    }
    printf("%d %d",start+1,i+1);

}
/*

cAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAodecubeodecube

*/
