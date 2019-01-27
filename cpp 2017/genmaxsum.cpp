#include<bits/stdc++.h>
#define cons 1000000
using namespace std;
main()
{
    int n;
    freopen("genmaxsum.txt","w",stdout);
    scanf("%d",&n);
    srand(time(NULL));
    printf("%d\n",n);
    for(int i = 0;i<n;i++)
    {
        int t = rand();
        t = t%cons;
        int t2 = rand();
        t*= (t2%2==0)?-1:1;
        printf("%d\n",t);
    }
}
