#include<bits/stdc++.h>
using namespace std;
const int mod = 29947;
int mem[351][351][351];
int f(int x,int y,int z)//0 mean xy, 1 mean yz , 2 mean xz
{
    if(x+y == 0 || y+z ==0 || x+z ==0)return 1;
    else if(!mem[x][y][z])
    {
        if(x-1>=0)mem[x][y][z] = (mem[x][y][z]+f(x-1,y,z))%mod;
        if(y-1>=0)mem[x][y][z] = (mem[x][y][z]+f(x,y-1,z))%mod;
        if(z-1>=0)mem[x][y][z] = (mem[x][y][z]+f(x,y,z-1))%mod;
        if(x-1>=0 && y-1 >=0 && z-1 >=0)mem[x][y][z] = (mem[x][y][z]+4*f(x-1,y-1,z-1))%mod;
        //if(x-2>=0 && y-2 >=0 && z-2 >=0)mem[x][y][z] = (mem[x][y][z]-f(x-2,y-2,z-2))%mod;
        if(z-1>=0 && y-1 >=0)mem[x][y][z] = (mem[x][y][z]-f(x,y-1,z-1))%mod;
        if(x-1>=0 && y-1 >=0)mem[x][y][z] = (mem[x][y][z]-f(x-1,y-1,z))%mod;
        if(z-1>=0 && x-1 >=0)mem[x][y][z] = (mem[x][y][z]-f(x-1,y,z-1))%mod;
        if(x-2>=0 && y-2 >=0 && z-2>=0 )mem[x][y][z] = (mem[x][y][z]-5*f(x-2,y-2,z-2))%mod;
        /*if(z-1>=0 && x-1 >=0)mem[x][y][z] = (mem[x][y][z]+f(x-1,y,z-1))%mod;
        if(z-1>=0 && x-1 >=0)mem[x][y][z] = (mem[x][y][z]+f(x-1,y,z-1))%mod;
        if(z-1>=0 && x-1 >=0)mem[x][y][z] = (mem[x][y][z]+f(x-1,y,z-1))%mod;*/
    }
    return mem[x][y][z];
}
main()
{
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    printf("%d",f(x-1,y-1,z-1));
}
