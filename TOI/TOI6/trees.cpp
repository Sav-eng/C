#include<bits/stdc++.h>
using namespace std;
vector<int>from[100001];
set<int>myset[100001];
char ans[100001];
main()
{
    bool check=1;
    int check2=0,a,b,n,i,l,r;
    int time=5;
    int mid;
    while(time--)
    {
        scanf("%d",&n);
        check = 1;
        for(i=0;i<n-1;i++)
        {
            scanf("%d%d",&a,&b);
            myset[a].insert(b);
            myset[b].insert(a);
        }
        for(i=0;i<n-1;i++)
        {
            scanf("%d%d",&a,&b);
            if(myset[a].find(b)==myset[a].end())check=0;
        }
        if(check)ans[check2++]='Y';
        else ans[check2++]='N';
        for(i=1;i<=n;i++)from[i].clear();
    }
    printf("%s",ans);
}
/*

9
2 4 9 4 6 4 1 4 1 5 3 5 7 5 7 8
1 4 4 9 1 5 6 4 3 5 7 5 7 8 2 4
9
2 4 9 4 6 4 1 4 1 5 3 5 7 5 7 8
1 4 9 4 1 5 2 4 6 4 3 5 7 5 7 8
9
2 4 6 4 1 4 1 5 9 4 3 5 7 5 7 8
1 4 9 4 1 5 2 4 6 4 3 5 7 5 7 8
9
9 4 3 5 7 5 7 8 2 4 6 4 1 4 1 5
1 4 9 4 1 5 2 4 6 4 3 5 7 5 7 8
4
1 2 2 3 3 4
1 2 1 3 1 4


*/
