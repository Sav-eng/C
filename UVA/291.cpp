#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,ord;
};
vector<node>from[9];
int tab[9];
int f(int x,int bit,int check)
{
    int i;
    if(bit==(1<<8)-1)
    {
        printf("1");
        for(i=0;i<8;i++)
        {
            printf("%d",tab[i]);
        }
        printf("\n");
    }
    else
    {
        for(i=0;i<from[x].size();i++)
        {
            if(!((bit>>from[x][i].ord)&1))
            {
                tab[check] = from[x][i].x;
                f(from[x][i].x,bit|(1<<from[x][i].ord),check+1);
            }
        }
    }
}
main()
{
    from[1].push_back({2,0});from[1].push_back({3,1});from[1].push_back({5,2});
    from[2].push_back({1,0});from[2].push_back({3,6});from[2].push_back({5,7});
    from[3].push_back({1,1});from[3].push_back({2,6});from[3].push_back({4,5});from[3].push_back({5,3});
    from[4].push_back({3,5});from[4].push_back({5,4});
    from[5].push_back({1,2});from[5].push_back({2,7});from[5].push_back({3,3});from[5].push_back({4,4});
    f(1,0,0);
}
