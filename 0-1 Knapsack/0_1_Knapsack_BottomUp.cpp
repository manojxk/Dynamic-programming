
#include <bits/stdc++.h>
using namespace std;
int dp[4][51];
int knapSack(int W, int wt[], int val[], int n)
{
    //Base case
    //if(n == 0 || W == 0) return 0;
    //base condition of recursion
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 51; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < 4; i++)
    {
        for (int j = 1; j < 51; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][W];
}

int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack(W, wt, val, n);
    return 0;
}