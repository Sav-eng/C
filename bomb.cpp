#include<bits/stdc++.h>
using namespace std;

string tab[502];
vector<int>boomed;
vector<int>notBoomed;
set<int>col,row;
int n,m,k;
bool boom(int x,int y){
  return col.find(y)!=col.end() || row.find(x) != row.end();
}
int main() {
  
  cin >> n >> m >> k;
  for(int i=0;i<n;i++){
    cin >> tab[i];
    for(int j=0;j<m;j++){
      if(tab[i][j]=='B'){
        col.insert(j);
        row.insert(i);
      }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(tab[i][j]!='B'){
        if(boom(i,j)){
          boomed.push_back(tab[i][j]-'0');
        } else {
          notBoomed.push_back(tab[i][j]-'0');
        }
      }
    }
  }
  sort(boomed.begin(),boomed.end());
  sort(notBoomed.begin(),notBoomed.end());
  int cnt=0;
  int cnt2=boomed.size()-1;
  int ans=0;
  for(int i=0;i<k;i++){
    if(cnt<notBoomed.size() && cnt2 > 0 && boomed[cnt2] > notBoomed[cnt]) ans += boomed[cnt2--],cnt++;
    else break;
  }
  while(cnt<notBoomed.size()){
    ans += notBoomed[cnt++];
  }
  cout << ans;
  return 0;
}
