#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int t;
	cin >> t;
	for(;t>0;t--){
		int w,n;
		cin >> w >> n;
		if(n==0){
			cout << w << endl;
			continue;
		}
		vector<int> v;
		v.push_back(-1);
		for(int i=0;i<n;i++){
			int x;
			cin >> x;
			v.push_back(x);
		}
		sort(v.begin(),v.end());
		if(w==0){
			cout << -v[n] << endl;
			continue;
		}
		
		vector<vector<int> > f;
		for(int i=0;i<w;i++){
			vector<int> x(n,0);
			f.push_back(x);
		}
		
		for(int i=0;i<w;i++)
			for(int j=1;j<n;j++){
				if(i-v[j]>=0){
					f[i][j] = max(v[j]+f[i-v[j]][j-1],f[i][j-1]);
				}
				else f[i][j] = f[i][j-1];
			}
		cout << w - f[w-1][n-1] - v[n] << endl;
	}
	return 0;
}
