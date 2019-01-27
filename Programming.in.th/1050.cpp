#include<bits/stdc++.h>
using namespace std;
struct node
{
    int tab[15],index;
};
int k;
bool cmp(node x,node y)
{
    int i;
    for(i=0;i<k;i++)
    {
        if(x.tab[i]<y.tab[i])return 1;
        else if(x.tab[i]>y.tab[i])return 0;
    }
    return 1;
}
node x[100005];
int s[100005];
node Find;
bool Check(int X,int Y)
{
    int i,j;
    for(i=0;i<k;i++)
    {
        if(x[X].tab[i]==x[Y].tab[i])continue;
        return 0;
    }
    return 1;
}
main()
{
    int n,i,j,lower,upper,L,R;
    bool check=0;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
    {
        x[i].index = i;
        for(j=0;j<k;j++)
        {
            scanf("%d",&x[i].tab[j]);
        }
    }
    for(i=0;i<k;i++)scanf("%d",&s[i]);
    sort(&x[0],&x[n],cmp);
    for(j=0;j<n;j++)
    {
        lower = 0;
        upper = n-1;
        check = 0;
        for(i=0;i<k;i++)
        {
            Find.tab[i] = s[i]-x[j].tab[i];
            //printf("%d ",Find.tab[i]);
            if(Find.tab[i]>0)check=1;
            if(Find.tab[i]<0)
            {
                check = 1;
                break;
            }
        }
        //printf("\n");
        if(i!=k && check)continue;
        if(!check)
        {
            printf("%d",x[j].index+1);
            return 0;
        }
        check = 0;
        int l,r,mid;
        for(i=0;i<k;i++)
        {
            L = lower,R = upper;
            lower = 0,upper = n-1;
            l = L,r = R;
            while(l<=r)
            {
                mid = (l+r)/2;
                if(x[mid].tab[i]>=Find.tab[i])
                {
                    r = mid-1;
                    lower = mid;
                }
                else l = mid+1;
            }
            l = L,r = R;
            while(l<=r)
            {
                mid = (l+r)/2;
                if(x[mid].tab[i]<=Find.tab[i])
                {
                    l = mid+1;
                    upper = mid;
                }
                else r = mid-1;
            }
            if(x[upper].tab[i] != Find.tab[i] || x[lower].tab[i] != Find.tab[i])
            {
                //printf("j--i %d--%d\n",j,i);
                check = 1;
                break;
            }
        }
        if(!check && x[j].index!=x[upper].index)
        {
            if(Check(upper,j))continue;
            if(x[j].index<x[upper].index)printf("%d %d",x[j].index+1,x[upper].index+1);
            else printf("%d %d",x[upper].index+1,x[j].index+1);
            return 0;
        }
    }
    printf("NO");

}

/*

3 2
1 2
3 4
5 6
1 2


4 4
1 1 1 5
1 1 1 5
1 1 1 2
1 1 1 1
2 2 2 10

1 3

3 2
1 2
3 4
5 6
6 8

NO
*/
