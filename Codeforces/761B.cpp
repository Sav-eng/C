#include<stdio.h>
#include<queue>
using namespace std;
queue<int>q;
int b[105];
int check[105];
main()
{
    int n,l,a,i,j,k,cnt;
    scanf("%d%d",&n,&l);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        check[a] = 1;
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    for(i=0;i<l;i++)
    {
        if(check[i]==1)q.push(1);
        else q.push(0);
    }
   /*for(i=0;i<l;i++)
    {
        printf("%d ",q.front());
        q.push(q.front());
        q.pop();
    }
    printf("\n");
    q.push(q.front());
    q.pop();
    for(i=0;i<l;i++)
    {
        printf("%d ",q.front());
        q.push(q.front());
        q.pop();
    }*/
    for(i=0;i<l;i++)
    {
        k=0;
        cnt=0;
        for(j=0;j<l;j++)
        {
            //printf("%d ",k);
            if(q.front()==1 && b[cnt]==k)
            {
                cnt++;
            }
            q.push(q.front());
            q.pop();
            k++;
        }
        if(cnt==n)
        {
            printf("YES");
            return 0;
        }
        /*for(j=0;j<l;j++)
        {
            printf("%d ",q.front());
            q.push(q.front());
            q.pop();
        }
        printf("\n");*/
        q.push(q.front());
        q.pop();
    }
    printf("NO");
}
