#include<bits/stdc++.h>
using namespace std;
int n,m,x,p,d,t;
long long mx;
vector<int>v[100001];
long long mem[100001];
long long c[100001];
void f(int x,int d){
//    printf("%d %d\n",x,d);
    if(mem[x]>d)return;
//    printf("%d %d\n",x,d);
    mem[x]=d;
    for(int i=0;i<v[x].size();i++){
        int nx=v[x][i];
        if(mem[nx]<mem[x]+1){
            f(nx,mem[x]+1);
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&x,&p);
        if(x<p)v[x].push_back(p);
        else v[p].push_back(x);
        c[x]++;
        c[p]++;
    }
    for(int i=1;i<=n;i++){
        sort(v[i].begin(),v[i].begin()+v[i].size());
    }
    for(int i=1;i<=n;i++){
        if(!mem[i]){
            f(i,1);
        }
        if(mem[i]*c[i]>mx)mx=mem[i]*c[i];
    }
    printf("%lld",mx);
}
/*
8 6
4 5
3 5
2 5
1 2
2 8
6 7

4 6
1 2
1 3
1 4
3 4
2 3
2 4
*/
