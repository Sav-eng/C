#include<bits/stdc++.h>
using namespace std;
map<int,vector< pair<int,int> > >from;
set<int> shop;
set<int> warp;
int main(){
	scanf("%d%d%d%d",&n,&m,&t,&k);
	for(int i=0;i<n;i++)scanf("%d",&s[i]),shop.insert(s[i]);
	for(int i=0;j<m;j++)scanf("%d",&w[i]),warp.insert(w[i]);
	sort(w.begin(),w.end());
	sort(s.begin(),s.end());
	from[0].push_back({t+1,w[0]});
	from[w[m-1]].push_back({t,t-w[m-1]});
	int val;
	for(int i=0;i<n;i++){
		if(!i)from[0].push_back({s[i],s[i]+1});
		else {
			from[s[i-1]].push_back({s[i],s[i]-s[i-1]+1});
			from[s[i]].push_back({s[i-1],s[i]-s[i-1]+1});
		}
		auto low = lower_bound(s.begin(),s.end(),s[i]);
		val = w[low-s.begin()]-s[i];
		if(low-s.begin() > 0) val = min(val,w[low-s.begin()-1]-s[i]);
		from[t+1].push_back({s[i],val+1});
		from[s[i]].push_back({t+1,val});
	}
	from[s[n-1]].push_back({t,t-s[n-1]});
	for(int i=0;i<n;i++){

	}
}