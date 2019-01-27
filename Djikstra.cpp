  /////////////////////////
 //  Dijkstra Algorithm //
/////////////////////////
#include<stdio.h>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;
struct node
{
    int x,val;
    //Overload operator
    bool operator < (node a) const
    {
        return a.val<val;
    }
    //Overload node's function (Create node)
    node(int _x = 0,int _val = 0)
    {
        x = _x;
        val = _val;
    }
};
vector<node> from[100005]; //Record the adjacency list of edge that going out direction from node i
priority_queue<node> heap; //Heap for calculating Shortest path
int mem[100005]; //mem[i] record shortest path from node s to node i
main()
{
    int n,m,s,e;
    int i,x,y,val;
    node t; //temp node
    //INPUT
    scanf("%d%d",&n,&m); //Num of Nodes(N) and Edges(M)
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&x,&y,&val); //Edge from node x to y using cost = val
        from[x].push_back(node(y,val)); //Add edge to node y in to the adjacency list of node x
    }
    scanf("%d%d",&s,&e); //s is the start node and e is the end node
    //RESET
    for(i=0;i<m;i++) mem[i] = INT_MAX; //Reset recorded path of all node to infinity
    //PREPARE
    mem[s] = 0;
    heap.push(node(s,0)); //Start search with node s and value 0
    //CALCULATE
    while(!heap.empty())
    {
        t = heap.top(); //Pop the heap
        heap.pop();
        if(t.x==e) //Find e in the top of the heap
        {
            printf("%d",t.val);
            break; //Stop
        }
        for(i=0;i<from[t.x].size();i++) //Look to all node that can go from this node
        {
            if(mem[from[t.x][i].x] > mem[t.x] + from[t.x][i].val) //If recorded path of that node is longer than path from this node to that node then Update and push the updated node in to the heap
            {
                mem[from[t.x][i].x] = mem[t.x] + from[t.x][i].val; //Update
                heap.push(node(from[t.x][i].x,mem[from[t.x][i].x])); //Add to the heap
            }
        }
    }
}
/*
6 9
0 1 7
0 2 9
0 5 14
1 2 10
1 3 15
2 3 11
2 5 2
3 4 6
4 5 9
0 4
ANS: 26
*/
