#include<bits/stdc++.h>
using namespace std;
vector<int>a;
int main(){
	int Q,T=1;
	string s;
	scanf("%d",&Q);
	while(Q--){
		cin >> s;
		a.clear();
		for(int i=0;i<s.size();i++)a.push_back(s[i]-'0');
		for(int i=9;i>0;i--){
			bool chk=false;
			for(int j=0;j<a.size();j++){
				if(a[j]==i){
					chk=true;
				}
			}
			if(chk){
				vector<int>op,cl;
				for(int j=0;j<a.size();j++){
					if(a[j]==i){
						op.push_back(j);
						a[j]--;
						j++;
						while((a[j]==i || a[j]==200 || a[j]==100) && j<a.size()){
							if(a[j]==i)a[j]--;
							j++;
						}
						cl.push_back(j);
					}
				}
				int x=op.size()-1,y=cl.size()-1;
				while(x>=0 && y>=0){
					if(op[x]<cl[y]){
						a.insert(cl[y]+a.begin(),200);
						y--;
					} else {
						a.insert(op[x]+a.begin(),100);
						x--;
					}
				}
				while(x>=0)a.insert(op[x--]+a.begin(),100);
				while(y>=0)a.insert(cl[y--]+a.begin(),200);
			}
		}
		cout << "Case #" << T++ << ": ";
		int j=0;
		for(int i=0;i<a.size();i++){
			if(a[i]==100)cout << '(';
			else if(a[i]==200)cout << ')';
			else cout << s[j++];
		}
		cout << endl;
	}
}