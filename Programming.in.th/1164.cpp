#include<stdio.h>
#include<limits.h>
#include<algorithm>
using namespace std;
struct node
{
    int a,b;
};
bool cmp(node x,node y)
{
    if(x.a==y.a)return x.b>y.b;
    return x.a<y.a;
}
node tab[1000005];
node tab1[1000005];
main()
{
    int _max = 0;
    int n,i,last=0;
    int l,r,mid;
    int maxa=INT_MIN,maxb=INT_MIN;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&tab[i].a,&tab[i].b);
    }
    sort(&tab[0],&tab[n],cmp);
    for(i=n-1;i>=0;i--)
    {
        if(_max <= tab[i].b)
        {
            _max = tab[i].b;
            tab1[last].a = tab[i].a;
            tab1[last].b = tab[i].b;
            last++;
        }
    }
    for(i=last-1;i>=0;i--)
    {
        printf("%d %d\n",tab1[i].a,tab1[i].b);
    }


}
/*
5
9 1
8 2
7 3
6 4
5 5


7
1 2
2 4
4 1
7 3
5 5
6 6
3 7

8
1 2
2 4
4 1
7 3
5 5
6 6
3 7
4 7

10
1 2
2 4
3 7
3 9
4 1
4 7
5 3
5 5
6 6
7 3

5
1 5
5 1
2 5
7 1
1 1
*/
