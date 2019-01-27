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
    return x.a<y.a;
}
node tab[1000005];
node ls[1000005];
main()
{
    int n,i,last=0;
    int l,r,mid;
    int maxa=INT_MIN,maxb=INT_MIN;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&tab[i].a,&tab[i].b);
    }
    sort(&tab[0],&tab[n],cmp);
    //for(i=0;i<n;i++)printf("%d %d\n",tab[i].a,tab[i].b);
    for(i=0;i<n;i++)
    {
        if(i==0)
        {
            ls[last]=tab[i];
            last++;
        }
        else
        {
            if(tab[i].b<=ls[last-1].b)
            {
                ls[last]=tab[i];
                last++;
            }
            else if(tab[i].b>ls[last-1].b)
            {
                l = 0;
                r = last;
                while(l<r)
                {
                    //printf("%d %d\n",l,r);
                    mid = l+r/2;
                    if( ls[mid].b < tab[i].b) r = mid;
                    else l = mid+1;
                }
                ls[r]=tab[i];
            }
        }

    }
    for(i=0;i<last;i++)
    {
        printf("%d %d\n",ls[i].a,ls[i].b);
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


*/
