#include<stdio.h>
#include<algorithm>
#define inf 1e9
using namespace std;
char a[100][100];
main()
{
    int n,m,i,ans1=inf,ans2=inf,ans3=inf,mindigit = inf,minsym = inf,minletter = inf,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%s",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        mindigit = inf;
        minletter = inf;
        minsym = inf;
        for(j=0;j<m;j++)
        {
            if(a[i][j]<='9' && a[i][j] >='0')mindigit = min(mindigit,min(j,m-j));
            else if(a[i][j] == '*' || a[i][j] == '#' || a[i][j] == '&')minsym = min(minsym,min(j,m-j));
            else if(a[i][j]<='z' && a[i][j] >='a')minletter = min(minletter,min(j,m-j));
        }
        ans1 = min(ans1,mindigit);
        ans2 = min(ans2,minsym);
        ans3 = min(ans3,minletter);
        //printf("%d %d %d\n",mindigit,minsym,minletter);
    }
    printf("%d",ans1+ans2+ans3);

}
