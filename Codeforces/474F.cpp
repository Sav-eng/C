#include<bits/stdc++.h>
#define MAXN 100001
using namespace std;
struct node
{
    int x,y,ind;
};
bool cmp(node x,node y)
{
    return x.x>y.x;
}
int ST[MAXN];
int TOS;
int top()
{
    return ST[TOS-1];
}
void push(int x)
{
    ST[TOS++] = x;
}
void pop()
{
    TOS--;
}
int R[MAXN];
int a[MAXN];
int L[MAXN];
node tab[MAXN];
int ans[MAXN];
main()
{
    int n,i,m;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    scanf("%d",&m);
    for(i=1;i<=m;i++)scanf("%d%d",&tab[i].x,&tab[i].y),tab[i].ind = i;
    sort(tab+1,tab+m+1,cmp);
    TOS = 1;
    for(i=1;i<=n;i++)
    {
        if(TOS==1 ||  a[i]%a[top()]==0)push(i);
        else
        {
            while(TOS>1 && a[i]%a[top()]!=0)
            {
                R[top()] = i-1;
                pop();

            }
            push(i);
        }
    }
    while(TOS>=1)
    {
        R[top()] = n;
        pop();
    }
    //for(i=1;i<=n;i++)printf("%d ",R[i]);
    //printf("\n");
    TOS = 1;
    int j=1;
    //for(i=0;i<m;i++)printf("%d %d\n",tab[i].x,tab[i].y);
    for(i=n;i>0;i--)
    {

        if(TOS==1 || a[i]%a[top()]==0)push(i);
        else
        {
            while(TOS>1 && a[i]%a[top()]!=0 )
            {
                L[top()] = i+1;
                pop();
                //printf("i = %d TOS = %d %d\n",i,TOS,top());
            }
            //printf("A");
            push(i);
        }
        //printf("i = %d j = %d\n",i,j);
        while(i==tab[j].x && j<=m)
        {
            int l,r,mid,t;
            l = 1, r = TOS-1;
            //printf("ST[] = ");
            //for(int i = 1;i<TOS;i++)printf("%d ",ST[i]);
            //printf("TOS-1 = %d",TOS-1);
            //printf("\n");
            while(l<=r)// mid max <= tab[j].y(R)
            {
                mid = (l+r)/2;
                //printf("%d///%d\n",ST[mid],tab[j].y);
                if(ST[mid]<=tab[j].y)
                {
                    r = mid-1;;
                    t = mid;
                }
                else
                {
                    l = mid+1;
                }
            }
            int t2;
            l = t,r = TOS-1;
            t2 = 0;
            while(l<=r)// mid min >= tab[j].y(R)
            {
                mid = (l+r)/2;
                //printf("\t\t");
                //printf("%d\\\%d %d\n",R[ST[mid]],tab[j].y,ST[mid]);
                if(R[ST[mid]]>=tab[j].y)
                {
                    t2 = mid;
                    l = mid+1;
                }
                else r = mid -1;
            }
            //printf("t = %d t2 = %d ",t,t2);
            int Ans = (t==0 || t2==0)?0:t2-t+1;
            //printf("Ans = %d ",Ans);
            ans[tab[j].ind] = tab[j].y-tab[j].x+1-Ans;
            //printf("\t\tans[%d] = %d(%d-%d)(%d)\n",tab[j].ind,ans[tab[j].ind],tab[j].x,tab[j].y,Ans);
            j++;
        }
    }
    //printf("L[] = ");
    //for(i=0;i<n;i++)printf("%d ",L[i]);
    for(i=1;i<=m;i++)printf("%d\n",ans[i]);
}

/*

5
3 1 6 2 8
3
1 5
3 4
3 5

*/
