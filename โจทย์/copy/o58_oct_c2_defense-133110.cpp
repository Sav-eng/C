#include<stdio.h>
#include<queue>
#include<set>

//STATE = [x,y]
struct STATE{
    int x;
    int y;
    int i;
    STATE(int _x = 0, int _y = 0, int _i = 0)
    { x = _x; y = _y; i = _i;}
};
bool operator< (STATE a, STATE b)
{ return (a.x < b.x || (a.x == b.x && a.y < b.y) || (a.x == b.x && a.y == b.y && a.i < b.i)); }

struct Next{
    int x;
    int y;
    int i;
    int dis;
    Next(int _x = 0, int _y = 0, int _i = 0, int _dis = 0)
    { x = _x; y = _y; i = _i; dis = _dis; }
};
bool operator< (Next a, Next b)
{ return a.dis > b.dis; }

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int A[4000];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    std::priority_queue<Next> next;
    std::set<STATE> visited;
    next.push(Next(0, 0, 0, 0));
    while(!next.empty())
    {
        Next t = next.top();
        next.pop();
        //printf("r : %d %d %d %d\n", t.x, t.y, t.i, t.dis);
        //invalid
        if(visited.count(STATE(t.x,t.y,t.i))) continue;
        if(t.y < t.i-k+1) continue;
        if(t.i >= n && !(t.y >= n-1)) continue;
        if(t.y >= n-1) {printf("%d", t.dis); return 0;}
        //choose i
        next.push(Next(t.i+k-1, t.x, t.i+1, t.dis + A[t.i]));
        //printf("w1 : %d %d %d %d\n", t.i+k-1, t.x, t.i+1, t.dis + A[t.i]);
        //not choose i
        next.push(Next(t.x, t.y, t.i+1, t.dis));
        //printf("w2 : %d %d %d %d\n", t.x, t.y, t.i+1, t.dis);
        visited.insert(STATE(t.x,t.y,t.i));
    }
}
