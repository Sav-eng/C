//O(NM)
#include<bits/stdc++.h>
using namespace std;

#define maxn 30005

int n,m;
int p[maxn];

int main() {
    int i,j,x;
    long long ans;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++) scanf("%d",&p[i]);
    for(i=0;i<m;i++) {
        scanf("%d",&x);
        ans = 0;
        for(j=0;j<n;j++) ans += min(p[j],x), p[j] = max(p[j]-x,0);
        printf("%lld\n",ans);
    }
}
