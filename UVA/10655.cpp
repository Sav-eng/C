#include<bits/stdc++.h>
using namespace std;
typedef vector<vector<long long> > matrix;
matrix mul(matrix X,matrix Y)
{
    matrix C(3,vector<long long>(4));
    int i,j,k;
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            for(k=0;k<2;k++)
            {
                C[i][j] += X[i][k]*Y[k][j];
            }
        }
    }
    return C;
}
matrix pow(matrix x,long long n)
{
    if(n==1)return x;
    if(n%2)return mul(x,pow(x,n-1));
    matrix X = pow(x,n/2);
    return mul(X,X);
}
main()
{
    //freopen("out.txt","w",stdout);
    int p,q,n,i,j;
    int F[4];
    matrix T(4,vector<long long>(4));
    while(scanf("%d%d",&p,&q) && scanf("%d",&n)!=EOF)
    {
        T[0][0] = 0; T[0][1]=1;
        T[1][0] = -q; T[1][1]=p;
        F[0]=2; F[1]=p;
        if(n==0)
        {
            printf("2\n");
            continue;
        }
        T = pow(T,n);
        long long ans=0;
        for(i=0;i<2;i++)ans += T[0][i]*F[i];
        printf("%lld\n",ans);
    }
}
