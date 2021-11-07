#include<bits/stdc++.h>
using namespace std;
pair<int,pair<int,int> >x[1005];
vector<pair<int,int> >ans;
int main(){
	int Q,T=1,n;
	scanf("%d",&Q);
	while(Q--){
		scanf("%d",&n);
		memset(x,0,sizeof(x));
		for(int i=0;i<n;i++) scanf("%d%d",&x[i].first,&x[i].second.first),x[i].second.second=i;
		sort(&x[0],&x[n]);
		ans.clear();
		int ta=0,tb=0;
		bool impossible = false;
		for(int i=0;i<n;i++){
			// printf("%d %d\n",x[i].first,x[i].second);
			if(ta<=x[i].first){
				ans.push_back({x[i].second.second,1});
				ta=x[i].second.first;
			} else if(tb<=x[i].first){
				ans.push_back({x[i].second.second,2});
				tb=x[i].second.first;
			} else impossible = true;
		}
		sort(ans.begin(),ans.end());
		printf("Case #%d: ",T++);
		if(!impossible){
			for(int i=0;i<ans.size();i++){
				if(ans[i].second==1)printf("C");
				else printf("J");
			}
		} else {
			printf("IMPOSSIBLE");
		}
		printf("\n");
	}
}

/*

99 150
1 100
100 301
2 5
150 250

1 100 C J
2 5 J C
99 150 J C
100 301 C J
150 250 J J

*/