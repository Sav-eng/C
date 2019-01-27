#include<stdio.h>
#include<algorithm>
using namespace std;
int a[105],b[105];
int main()
{
    freopen("hps.in","r",stdin);
    freopen("hps.out","w",stdout);
    int n,i,check,ans1=0,ans2=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
        if(a[i]==1 && b[i]==2)ans1++;
        else if(a[i]==2 && b[i]==3)ans1++;
        else if(a[i]==3 && b[i]==1)ans1++;
        if(b[i]==1 && a[i]==2)ans2++;
        else if(b[i]==2 && a[i]==3)ans2++;
        else if(b[i]==3 && a[i]==1)ans2++;
    }
    printf("%d",max(ans1,ans2));
}
/*

5
1 2
2 2
1 3
1 1
3 2


*/
