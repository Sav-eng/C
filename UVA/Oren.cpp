#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
int head[1000];
bool bx;
struct street
{
    char start,ended;
    int val;
    bool operator < (street a)const
    {
        return a.val<val;
    }
};
char yon(char x)
{
    if(head[x]==x)return x;
    else return yon(head[x]);
}
void chead(char x,char y)
{
    if(yon(x)==yon(y))
    {
        bx=0;
        return;
    }
    else
    {
        head[yon(x)]=head[yon(y)];
    }
}

street x;
priority_queue<street> heap;
main()
{
    int n,i,j;
    int k;
    int t,ti;
    int a[100][100];
    scanf("%d",&t);
    for(ti=0;ti<t;ti++)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(j==n-1) scanf(" %d",&a[i][j]);
                else scanf(" %d,",&a[i][j]);
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i][j]!=0 && i>j)
                {
                    x.start = 'A'+j;
                    x.ended = 'A'+i;
                    x.val = a[i][j];
                    heap.push(x);
                }
            }
        }
        for(i='A';i<='Z';i++)
        {
            head[i]=i;
        }
        printf("Case %d:\n",ti+1);
        while(!heap.empty())
        {
            bx=1;
            x = heap.top();
            chead(x.start,x.ended);
            if(bx==1)printf("%c-%c %d\n",x.start,x.ended,x.val);
            heap.pop();
        }
    }

}
