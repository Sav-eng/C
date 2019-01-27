#include<stdio.h>
#include<algorithm>
using namespace std;
struct node
{
    int x,y;
    bool operator <(node a)const
    {
        if(a.x==x)return y>a.y;
        return x<a.x;
    }
};
node mem[100005];
node ans[100005];
main()
{
    bool check=0;
    int m,i=0,n,_max=0,_min=0,_maxt=0,cnt=0;
    scanf("%d",&m);
    while(scanf("%d%d",&mem[i].x,&mem[i].y) && (mem[i].x || mem[i].y))
    {
        i++;
    }
    n = i;

    sort(&mem[0],&mem[n]);
    /*printf("\\\\\\\\\\\\\\\\\\\\\n");
    for(i=0;i<n;i++)
    {
        printf("%d %d\n",mem[i].x,mem[i].y);
    }
    printf("\\\\\\\\\\\\\\\\\\\\\n");*/
    i=0; _max = 0; _maxt=0;
    while(i<n && _max<m && cnt<n)
    {
        while(mem[i].x<=_max && i<n)
        {
            _maxt = max(_maxt,mem[i].y);
            if(_maxt == mem[i].y)_min = mem[i].x;
            //printf("i  = %d _maxt = %d _min = %d\n",i,_maxt,_min);
            i++;
        }
        //printf("\\\\\\\\\\\\\\\\\\\\\\\\\n");
        ans[cnt].y = _maxt;
        ans[cnt].x = _min;
        //printf("%d %d %d %d\n",ans[cnt].x,ans[cnt].y,_maxt,i);
        cnt++;
        _max = _maxt;
    }
    //printf("%d",ans[cnt-1].y);
    if(cnt!=0 && ans[cnt-1].y>=m)
    {
        printf("%d\n",cnt);
        for(i=0;i<cnt;i++)
        {
            printf("%d %d\n",ans[i].x,ans[i].y);
        }
    }
    else printf("No solution");
}

/*

5
-2 3
3 5
-1 2
2 5
0 0

5
0 3
0 2
2 4
3 5
0 0

*/
