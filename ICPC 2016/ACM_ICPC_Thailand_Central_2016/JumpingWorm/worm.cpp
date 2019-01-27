#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define INF (1e6-1)
#define min(x,y)  ((x)<(y))?(x):(y)

int A[1001][1001];

using namespace std;

void PrintArray(int* a, int n)
{
    for(int i=0; i<n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    int K;
    cin >> K;
    for (int k=0; k<K; k++)
    {   int n;
        cin >> n;
        int H[n], U[n], D[n];
        for (int i=0; i<n; i++)
            cin >> H[i];
        for (int i=0; i<n; i++)
            cin >> U[i];
        for (int i=0; i<n; i++)
            cin >> D[i];


        int max_h = H[0];
        for (int i=0; i<n; i++)
            if (max_h < H[i])
                max_h = H[i];

        //int A[n][max_h+1];
        for (int i=0; i<n; i++)
            for(int j=0; j<=max_h; j++)
                A[i][j] = INF+1;


        int u,d,prev_j;
        for(int i=0; i<n; i++)
        {   u=U[i]; d=D[i];
            for(int j=0; j<=max_h; j++)
            {
                if (j==0)
                {   if (i==0)
                        A[0][0] = 0;
                    else
                    {
                        A[i][j]= INF;
                        /// From previous pole
                        prev_j = j+d;
                        if (prev_j>H[i-1])
                            prev_j = H[i-1];
                        for(int jj=prev_j; jj>=0; jj--)
                            A[i][j] = min(A[i][j], A[i-1][jj] + 2);
                    }
                }
                else if (j==H[i])
                {
                    A[i][j]= INF;
                    /// From previous pole
                    if (i-1>=0)
                    {   for(int jj=H[i-1]; jj>=j; jj--)
                            A[i][j] = min(A[i][j], A[i-1][jj] + 1);
                    }
                    /// From the same pole
                    prev_j = j-u;
                    if (prev_j < 0)
                        prev_j = 0;
                    for(int jj=prev_j; jj<H[i]; jj++)
                        A[i][j] = min(A[i][j], A[i][jj] + 1);
                }
                else if (j<H[i])
                {
                    A[i][j]= INF;
                    /// From previous pole
                    prev_j = j+d;
                    if ((i-1>=0)&&(prev_j>=j)&&(prev_j<=H[i-1]))
                        A[i][j] = min(A[i][j], A[i-1][prev_j]+2);

                    /// From the same pole
                    prev_j = j-u+d;
                    if ((prev_j >=0 ) && (prev_j < j) && (j+d < H[i]))
                    {   A[i][j] = min(A[i][j], A[i][prev_j]+2);
                    }
                }
            }
        }

        int ans = A[n-1][H[n-1]];
        if (ans == INF)
            cout << "NEVER" << endl;
        else
            cout << ans << endl;
//        /// Debug
//        for(int j=max_h; j>=0; j--)
//        {   cout << "   ";
//            for(int i=0; i<n; i++)
//                printf("%8d  ",A[i][j]);
//            cout << endl;
//        }
//        cout << endl << endl;
//
    }
    return 0;
}
