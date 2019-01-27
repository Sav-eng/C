#include<stdio.h>
#include<algorithm>
#include<vector>
#define inf 1e9
using namespace std;
bool cmp(int x,int y)
{
    return x<y;
}
vector<long long>from[1000005];
int ans[1000005];
main()
{
    int n,i,m,j,a,b,_max,_ans;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&a);
            from[i].push_back(a);
        }
    }
    for(i=0;i<n;i++)
    {
        sort(&from[i][0],&from[i][m],cmp);
    }
    for(j=0;j<m;j++)
    {
        _max = 0;
        for(i=0;i<n;i++)
        {
            if(from[i][j]>_max)
            {
                //printf("%d ",_max);
                _max = from[i][j];
                b = i;
            }
        }
        ans[b]++;
    }
    _max = 0;
    for(i=0;i<n;i++)
    {
        //printf("%d ",ans[i]);
        if(_max<ans[i])
        {
            _max = ans[i];
            _ans = i;
        }
        //_ans = max(_ans,ans[i]);
    }
    printf("%d",_ans+1);

}

