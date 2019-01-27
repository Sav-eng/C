#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>

int main()
{
    std::vector<int> availablenum;
    int coin[1000];
    int n = 2;
    scanf("%d %d", &coin[0], &coin[1]);

    std::priority_queue<int, std::vector<int>, std::greater<int> > nextnum;
    nextnum.push(0);
    while(!nextnum.empty())
    {
        int thisnum = nextnum.top();
        nextnum.pop();
        if(std::find(availablenum.begin(), availablenum.end(), thisnum) == availablenum.end() && thisnum <= 10000)
        {
            availablenum.push_back(thisnum);
            for(int i = 0; i < n; i++)
                nextnum.push(thisnum + coin[i]);
        }
    }

    int m;
    int num;
    scanf("%d", &m);


    for(int i = 0; i < m; i++)
    {
        scanf("%d", &num);
        printf("%d\n", *std::lower_bound(availablenum.begin(), availablenum.end(), num));
    }

}
