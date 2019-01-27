#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
struct node
{
    int x,y,val;
    node(int _x=0,int _y=0, int _val = 0)
    {
        x = _x;
        y = _y;
        val = _val;
    }
    bool operator < (node a)const
    {
        return a.val<val;
    }
};
int head[1005];
int root(int x)
{
    if(x!=head[x])return root(head[x]);
    else return x;
}
int buc[1005];
int x[1005];
int y[1005];
priority_queue<node>heap;
main()
{
    int n,i,j,d,check,k;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            d = (x[i]-x[j])*(x[i]-x[j]) +(y[i]-y[j])*(y[i]-y[j]);
            heap.push(node(i,j,d));
        }
    }
    for(i=0;i<n;i++)
    {
        head[i] = i;
    }
    node t;
    //printf("%d",k);
    while(!heap.empty())
    {
        t = heap.top();
        heap.pop();
        //printf("%d %d ",t.x,t.y);
        if(root(t.x)!=root(t.y))
        {
            check =0;
            head[root(t.x)]=head[root(t.y)];
            for(i=0;i<n;i++)buc[i]=0;
            for(i=0;i<n;i++)
            {
                //printf("%d",head[i]);
                if(buc[root(i)]==0)
                {
                    check++;
                    buc[root(i)]=1;
                }
            }
            //printf(" check = %d\n",check);
            if(check==k)
            {
                //printf("a");
                break;
            }
        }
    }
    printf("%d",t.val);

}
/*
10 2
366 409
248 374
485 127
745 944
313 261
362 115
370 55
546 876
341 474
748 293

96725

10 5
712 420
413 638
854 53
152 430
430 703
248 450
758 388
653 578
2 302
637 198

38884
*/
