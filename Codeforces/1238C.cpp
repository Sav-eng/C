#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
int n,m;
int tab[200002];
set<int>s;
map<int,int>mp;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int Q;
	cin >> Q;
	while(Q--){
		cin >> n >> m;
		s.clear();
		mp.clear();
		for(int i=0;i<m;i++){
			cin >> tab[i];
			s.insert(tab[i]);
			mp[tab[i]] = i;
		}
		tab[m] = 0;
		mp[tab[m]] = m;
		s.insert(tab[m]);
		int now = tab[0];
		int ans = 0;
		for(int i=1;i<m;i++){
			if(i+1<=m && s.find(now-1)!=s.end() && s.find(now-2)!=s.end()){
				now-=2;
				i=mp[now];
			}
			else if(now-tab[i]==1 && tab[i]){
				now=tab[i];
				ans++;
				// cout << "JOIN";
			}
			else {
				now=tab[i]+1;
				// cout << "THIS IS NOW " << now << " THIS IS TAB+1 " << tab[i]+1 << " THIS IS I " << i << endl;
				i--;
			}
			// cout << "\\\\\\\\\\\\\\\\\\\\\\" << ans << "\\\\\\\\\\\\\\\\\\\\" << now << "\\\\\\\\\\\\" << i << endl;
		}
		cout << ans << endl;
	} 
	return 0;
}
