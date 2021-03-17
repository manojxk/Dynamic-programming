
#include <bits/stdc++.h>
using namespace std;

int dp[2000][2000];

bool subsetSum(int set[], int n, int sum)
{
    //Base case
    //if(n == 0 || W == 0) return 0;
    //base condition of recursion
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 51; j++){
            if (i == 0){
                dp[i][j] = 0;
            }
            if(j == 0){
                dp[i][j] = 1;
            }
        }
    }
    for (int i = 1; i < 4; i++){
        for (int j = 1; j < 51; j++){
            if (set[i - 1] <= j){
                dp[i][j] =  dp[i - 1][j - set[i - 1]] or dp[i - 1][j];
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}

int main()
{
	// Storing the value -1 to the matrix
	memset(dp, -1, sizeof(dp));
	int n = 5;
	int a[] = {1, 5, 3, 7, 4};
	int sum = 12;

	if (subsetSum(a, n, sum))
	{
		cout << "YES" << endl;
	}
	else
		cout << "NO" << endl;

	/* This Code is Contributed by Ankit Kumar*/
}

