#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
string s,e;
int n,m;
int mem[25][25];
int trac[25][25];
int f(int x,int y)
{
    if(x==n && y==m)return 0;
    else if(x==n && y!=m)
    {
        mem[x][y] = f(x,y+1)+1;
        trac[x][y] = 1;
    }
    else if(y==m && x!=n)
    {
        mem[x][y] = f(x+1,y)+1;
        trac[x][y] = 2;
    }
    else if(mem[x][y]==-1)
    {
        mem[x][y] = inf;
        if(s[x]==e[y])
        {
            if(mem[x][y]>f(x+1,y+1))
            {
                mem[x][y] = f(x+1,y+1);
                trac[x][y] = 4;// 4 mean choose
            }
        }
        if(mem[x][y]>f(x+1,y)+1)
        {
            mem[x][y] = f(x+1,y)+1;
            trac[x][y] = 2;// 2 mean delete
        }
        if(mem[x][y]>f(x,y+1)+1)
        {
            mem[x][y] = f(x,y+1)+1;
            trac[x][y] = 1;// 1 mean insert
        }
        if(mem[x][y]>f(x+1,y+1)+1)
        {
            mem[x][y] = f(x+1,y+1)+1;
            trac[x][y] = 3;// 3 mean change
        }
    }
    //printf("mem[%d][%d] = %d\n",x,y,mem[x][y]);
    return mem[x][y];
}
main()
{
    //freopen("out.txt","w",stdout);
    string a;
    int pos,x,y,time;
    while(getline(cin,a) && a!="#" )
    {
        memset(trac,0,sizeof(trac));
        memset(mem,-1,sizeof(mem));
        pos = a.find(" ");
        s = a.substr(0,pos);
        e = a.substr(pos+1,a.size());
        n = s.size(); m = e.size();
        time = f(0,0);
        x=0;y=0;
        int t;
        int cnt=0;
        string t2;
        int i;
        while(x!=n || y!=m)
        {
            if(trac[x][y]==1)//insert
            {
                t = x+cnt+1;
                cout << "I" << e[y];
                if(t<10)printf("0",t);
                printf("%d",t);
                cnt++;
                y++;
            }
            else if(trac[x][y]==2)//delete
            {
                t = x+cnt+1;
                cout << "D" << s[x];
                if(t<10)printf("0",t);
                printf("%d",t);
                cnt--;
                x++;
            }
            else if(trac[x][y]==3)//change
            {
                t =  x+cnt+1;
                cout << "C" << e[y];
                if(t<10)printf("0",t);
                printf("%d",t);
                x++;
                y++;
            }
            else
            {
                x++;
                y++;
            }
            //printf("trac[%d][%d] = %d\n",x,y,trac[x][y]);
        }
        cout << "E" << endl;
    }
}
/*
abcde bcgfe


*/
