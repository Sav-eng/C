#include<bits/stdc++.h>
using namespace std;
int n,k;
int mem[101];
int a;
int i,j,face;
int _min,_max;
main()
{
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        mem[a]++;
        _min = 101;
        _max = 0;
        for(j=1;j<=6;j++)
        {
            _min = min(_min,mem[j]);
            _max = max(_max,mem[j]);
            if(_max==mem[j])face=j;
        }
        if(_max-_min>=k)
        {
            printf("%d",face);
            return 0;
        }
    }
    printf("OK");
}
/*
8 3
4
5
4
4
1
3
2
6


*/
