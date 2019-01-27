#include<bits/stdc++.h>
using namespace std;
const int inf = 1e6;
bool check[10000001];
int mem[inf];
main()
{
    srand(time(NULL));
    int n,m,k,i,j;
    freopen("10.in","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    printf("%d %d %d\n",n,m,k);
    for(i=1;i<=m;i++)mem[i] = i;
    for(i=1;i<=m;i++)swap(mem[i],mem[(rand()%i)+1]);
    for(i=1;i<=m;i++)printf("%d ",mem[i]);
    printf("\n");
    for(i=1;i<=k;i++)mem[i] = i;
    for(i=1;i<=k;i++)
    {
        swap(mem[i],mem[(rand()%i)+1]);
    }
    for(i=1;i<=k;i++)printf("%d ",mem[i]);

}
/*
100000 10000 9000
1000000 900000  1000000
1000000 1000000 1000000

10 9 8
*/
