#include<bits/stdc++.h>
using namespace std;

#define maxn 30005

int N,M;
int P[maxn];
int A[maxn];
long long ANS[maxn];

void init(int x) {
    char iname[15] = "input??.txt";
    char oname[15] = "output??.txt";
    iname[5] = oname[6] = x/10 + '0';
    iname[6] = oname[7] = x%10 + '0';
    freopen(iname,"r",stdin);
    freopen(oname,"w",stdout);
}

void read() {
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++) scanf("%d",&P[i]);
    for(int i=0;i<M;i++) scanf("%d",&A[i]);
}

void solve() {
    memset(ANS,0,sizeof(ANS));
    for(int i=0;i<M;i++) {
        for(int j=0;j<N;j++) {
            ANS[i] += min(P[j],A[i]);
            P[j] = max(P[j]-A[i],0);
        }
    }
}

void write() {
    for(int i=0;i<M;i++) printf("%lld\n",ANS[i]);
}

main() {
    for(int cnum=0;cnum<10;cnum++) {
        cerr << "Solving " << cnum << endl;
        init(cnum);
        read();
        solve();
        write();
    }
}
