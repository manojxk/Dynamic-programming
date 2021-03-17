
#include <bits/stdc++.h>
using namespace std;



int dp[20][20];

int findCnt(int set[], int n, int sum)
{

    for (int i = 0; i < 20; i++){
        for (int j = 0; j < 20; j++){
            if (i == 0){
                dp[i][j] = 0;
            }
            if(j == 0){
                dp[i][j] = 1;
            }
        }
    }
    for (int i = 1; i < 20; i++){
        for (int j = 1; j < 20; j++){
            if (set[i - 1] <= j){
                dp[i][j] =  dp[i - 1][j - set[i - 1]] + dp[i - 1][j];
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}

// Driver code
int main()
{
    memset(dp, -1, sizeof(dp));
	int arr[] = { 3, 3, 3, 3 };
	int n = sizeof(arr) / sizeof(int);
	int x = 6;

	cout << findCnt(arr,n,x);

	return 0;
}
