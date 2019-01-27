#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int n,m;
ull mem[2510][2510];
ull mem2[2510][2510];
map<pair<pair<int,int>,pair<int,int> >,pair<ull,ull> >mp;
void add(int x,int y,ull val,ull val2)
{
    int X,Y;
    for(X=x;X<=n;X+=X&-X)
    {
        for(Y=y;Y<=m;Y+=Y&-Y)
        {
            mem[X][Y] += val;
            mem2[X][Y] += val2;
        }
    }
}
pair<ull,ull> query(int x,int y)
{
    pair<ull,ull> ans;
    ans = {0,0};
    int X,Y;
    for(X=x;X>0;X-=X&-X)
    {
        for(Y=y;Y>0;Y-=Y&-Y)
        {
            ans.first+=mem[X][Y];
            ans.second+=mem2[X][Y];
        }
    }
    return ans;
}
main()
{
    int T,operation,r1,c1,r2,c2,i,j;
    scanf("%d%d%d",&n,&m,&T);
    srand(20001206);
    while(T--)
    {
        scanf("%d%d%d%d%d",&operation,&r1,&c1,&r2,&c2);
        if(operation==1)
        {
            ull t1 = rand();
            ull t2 = rand();
            //printf("%I64d %I64d\n",t1,t2);
            mp[make_pair(make_pair(r1,c1),make_pair(r2,c2))] = make_pair(t1,t2);
            add(r1,c1,t1,t2);
            add(r1,c2+1,-t1,-t2);
            add(r2+1,c1,-t1,-t2);
            add(r2+1,c2+1,t1,t2);
        }
        else if(operation ==2)
        {
            pair<ull,ull> t = mp[make_pair(make_pair(r1,c1),make_pair(r2,c2))];
            add(r1,c1,-t.first,-t.second);
            add(r1,c2+1,t.first,t.second);
            add(r2+1,c1,t.first,t.second);
            add(r2+1,c2+1,-t.first,-t.second);
        }
        else
        {
            pair<ull,ull> t1 = query(r1,c1);
            pair<ull,ull> t2 = query(r2,c2);
            if(t1 != t2)printf("No\n");
            else printf("Yes\n");
        }
    }
}

/*
5 5 3
1 1 1 1 1
1 3 3 3 3
3 2 2 4 4

*/
/*#include <bits/stdc++.h>
#define Maxn 2507
using namespace std;
int n,m,q;
map<pair<pair<int,int>,pair<int,int> >,pair<unsigned long long,unsigned long long> > mp;
pair<unsigned long long,unsigned long long> s[Maxn][Maxn];
void add(int x,int y,pair<unsigned long long,unsigned long long> del)
{
	for (int kx=x;kx<=2503;kx+=kx&(-kx))
		for (int ky=y;ky<=2503;ky+=ky&(-ky))
		{
			s[kx][ky].first+=del.first;
			s[kx][ky].second+=del.second;
		}
}
pair<unsigned long long,unsigned long long> query(int x,int y)
{
	pair<unsigned long long,unsigned long long> res=make_pair(0,0);
	for (int kx=x;kx;kx-=kx&(-kx))
		for (int ky=y;ky;ky-=ky&(-ky))
		{
			res.first+=s[kx][ky].first;
			res.second+=s[kx][ky].second;
		}
	return res;
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	memset(s,0,sizeof(s));
	srand(20001206);
	mp.clear();
	for (int i=1;i<=q;i++)
	{
		int t,r1,c1,r2,c2;
		scanf("%d%d%d%d%d",&t,&r1,&c1,&r2,&c2);
		pair<unsigned long long,unsigned long long> del,udel;
		if (t==1)
		{
			del.first=rand();
			del.second=rand();
			printf("%I64d %I64d",del.first,del.second);
			udel=make_pair(-del.first,-del.second);
			mp[make_pair(make_pair(r1,c1),make_pair(r2,c2))]=del;
			add(r1,c1,del);
			add(r1,c2+1,udel);
			add(r2+1,c1,udel);
			add(r2+1,c2+1,del);
		} else if (t==2)
		{
			del=mp[make_pair(make_pair(r1,c1),make_pair(r2,c2))];
			mp[make_pair(make_pair(r1,c1),make_pair(r2,c2))]=make_pair(0,0);
			udel=make_pair(-del.first,-del.second);
			add(r1,c1,udel);
			add(r1,c2+1,del);
			add(r2+1,c1,del);
			add(r2+1,c2+1,udel);
		}
		else
		{
			del=query(r1,c1);
			udel=query(r2,c2);
			if (del==udel) printf("Yes\n"); else printf("No\n");
		}
	}
	return 0;
}
*/
