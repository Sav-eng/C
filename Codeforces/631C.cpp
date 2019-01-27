#include<bits/stdc++.h>
using namespace std;
int tab[200001];
int tab2[200001];
int a[200001];
int b[200001];
main()
{
    int n,m,i,x,y,cnt=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        b[i] = a[i];
    }
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        y--;
        while(tab[cnt-1]<=y && cnt-1 >=0)cnt--;
        tab2[cnt] = x; tab[cnt] = y;
        cnt++;
    }
    //printf("cnt = %d\n",cnt);
    //for(i=0;i<cnt;i++)printf("%d ",tab[i]);
    sort(&b[0],&b[tab[0]+1]);
    int j = 0;
    int l =0 , r = tab[0],cnt2 = tab[0];
    //printf("cnt2  = %d r =  %d\n",cnt2,r);
    //for(i=0;i<=tab[0];i++)printf("%d ",b[i]);
     //printf("\n\\\\\\\\\\\\\\\\\\\\\\\n");
    tab[cnt] = 0;
    for(i=1;i<=cnt;i++)
    {
        x = 0;
        while(tab[i-1]-tab[i]-x>0)
        {
            //printf("%d--->%d (%d)\n",tab[i-1],tab[i],cnt2);
            a[cnt2--] = (tab2[i-1]==1)?b[r--]:b[l++];
            x++;
        }
    }
    a[0] = (tab2[cnt-1]==1)?b[r]:b[l];
    for(i=0;i<n;i++)printf("%d ",a[i]);

}
