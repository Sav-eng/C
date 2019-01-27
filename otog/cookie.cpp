#include<bits/stdc++.h>
using namespace std;
string s;
struct node
{
    int x;
    node *l,*r;
    node(int _x)
    {
        x = _x;
        l = NULL;
        r = NULL;
    }
};
int cnt = 0;
int ans[1000001];
int t;
void dfs(node* u)
{
    if(u->l != NULL)dfs(u->l);
    ans[u->x] = ++t;
    if(u->r != NULL)dfs(u->r);
}
node *root;
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,i,j,N;
    cin >> n;
    root = new node(0);
    for(i=0;i<n;i++)
    {
        cin >> s;
        //cout << "\t" << s << endl;
        N = s.size();
        node* now = root;
        for(j=0;j<N-1;j++)
        {
            if(s[j]=='L')
            {
                if(now->l==NULL)now->l = new node(i);
                now = now->l;
            }
            else
            {
                if(now->r==NULL)now->r = new node(i);
                now = now->r;
            }
        }
    }
    t =  0;
    dfs(root);
    for(i=0;i<n;i++)printf("%d\n",ans[i]);
}
/*
7
*
R*
RR*
RRL*
RRLL*
L*
LR*

*/
