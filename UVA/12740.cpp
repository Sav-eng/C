#include<bits/stdc++.h>
#define mod 1000000009
using namespace std;
typedef vector<vector<long long> >matrix;
matrix mul(matrix X,matrix Y)
{
    matrix C(5,vector<long long>(5));
    int i,j,k;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            for(k=0;k<3;k++)
            {
                C[i][j]  =(C[i][j]+(X[i][k]*Y[k][j]+mod)%mod)%mod;
            }
        }
    }
    return C;
}
matrix pow(matrix x,long long n)
{
    if(n==1)return x;
    else if(n%2!=0)return mul(x,pow(x,n-1));
    matrix X = pow(x,n/2);
    return mul(X,X);
}
main()
{
    matrix T(5,vector<long long>(5));
    int F[5];
    long long n;
    int i,j,ans;
    while(scanf("%lld",&n)&&n)
    {
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(i+1==j || i==2)T[i][j] =1;
                else T[i][j]=0;
            }
        }
        F[0]=0;
        F[1]=1;
        F[2]=2;
        if(n==1)
        {
            printf("0\n");
            continue;
        }
        T = pow(T,n-1);
        long long ans=0;
        for(i=0;i<3;i++)
        {
            ans = (ans+(F[i]*T[0][i]+mod)%mod)%mod;
        }
        printf("%lld\n",ans);
    }
}
