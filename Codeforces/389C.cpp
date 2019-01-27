#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;
map<char,int>check;
char c[5] = "LRUD";
main()
{
    char a[250000];
    int n,i,ans=0,j;
    scanf("%d",&n);
    scanf("%s",&a);
    for(i=0;i<strlen(a);i++)
    {
        if((check['L']==1 && a[i] == 'R') || (check['R']==1 && a[i]=='L') || (check['U'] == 1 && a[i]=='D') || (check['D'] == 1 && a[i] == 'U'))
        {
            ans++;
            for(j=0;j<4;j++)
            {
                check[c[j]] = 0;
            }

        }
        check[a[i]]= 1;
    }
    printf("%d",ans+1);

}
