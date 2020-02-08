#include<bits/stdc++.h>
#define MAXN 10000001
using namespace std;
int tree[4*MAXN];
int n,check;
void update(int x,int y){
	
}
int main(){
	int ans=1;
	cin >> n >> Q;
	while(Q--){
		int x,y;
		cin >> x >> y; 
		update(x,y);
		if(check==(1<<k)) {
			cout << ans;
			break;
		}
		ans++;
	}
	return 0;
}b;