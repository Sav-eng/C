#include<stdio.h>
#include<algorithm>
#define inf 1e9
using namespace std;
int mp[100];
int mem[2][4][4][4][4];
bool check[5];
char a[100005];
main()
{
    int checka,checkb,n,i,j,k,p,q,ans,o;
    //freopen("out.txt","r",stdin);
    bool flag=0;
    mp['M'] = 1;
    mp['B'] = 2;
    mp['F'] = 3;
    scanf("%d",&n);
    scanf(" %s",&a);
    for(i=0;i<2;i++)for(j=0;j<4;j++)for(k=0;k<4;k++)for(p=0;p<4;p++)for(q=0;q<4;q++)mem[i][j][k][p][q] = -inf;
    mem[0][0][0][0][0] = 0;
    ans = 0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<4;j++)
        {
            for(k=0;k<4;k++)
            {
                for(p=0;p<4;p++)
                {
                    for(q=0;q<4;q++)
                    {
                        check[j]=1;check[k]=1;check[mp[a[i]]]=1;
                        checka=0,checkb=0;
                        for(o=1;o<=3;o++)if(check[o])checka++,check[o]=0;
                        check[p]=1;check[q]=1;check[mp[a[i]]]=1;
                        for(o=1;o<=3;o++)if(check[o])checkb++,check[o]=0;
                        mem[!flag][k][mp[a[i]]][p][q] = max(mem[!flag][k][mp[a[i]]][p][q],mem[flag][j][k][p][q]+checka);
                        mem[!flag][j][k][q][mp[a[i]]] = max(mem[!flag][j][k][q][mp[a[i]]],mem[flag][j][k][p][q]+checkb);
                        if(i==n-1)ans = max(ans,max(mem[!flag][k][mp[a[i]]][p][q],mem[!flag][j][k][q][mp[a[i]]]));
                    }
                }
            }

        }
        flag = !flag;
        //if(i%1000==0)printf("%d %d %c\n",i,mem[!flag][1][1][0][0],a[i]);
    }
    printf("%d",ans);
}
