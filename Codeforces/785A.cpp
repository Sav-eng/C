#include<bits/stdc++.h>
using namespace std;
map<string,int>mymap;
string a;
main()
{
    int n,ans=0,i;
    mymap["Tetrahedron"] = 4;
    mymap["Cube"] = 6;
    mymap["Octahedron"] = 8;
    mymap["Dodecahedron"] = 12;
    mymap["Icosahedron"] = 20;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        cin >> a;
        ans += mymap[a];
    }
    printf("%d",ans);
}
