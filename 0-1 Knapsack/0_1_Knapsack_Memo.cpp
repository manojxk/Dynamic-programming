
#include <bits/stdc++.h>
using namespace std;
int dp[101][1001];

int knapSack(int W, int wt[], int val[], int n)
{
    /*Here Weight and n are changing
    so make a table dp[n][W */
    //Base case
    if (n == 0 || W == 0)
        return 0;
    if (dp[n][W] != -1)
        return dp[n][W];

    if (wt[n - 1] <= W)
        return dp[n][W] = max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));
    else
        return dp[n][W] = knapSack(W, wt, val, n - 1);
    
}

int main()
{
    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 1001; j++)
        {
            dp[i][j] = -1;
        }
    }

    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack(W, wt, val, n);
    return 0;
}