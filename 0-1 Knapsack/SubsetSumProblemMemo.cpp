// CPP program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Taking the matrix as globally
int dp[2000][2000];

// Check if possible subset with 
// given sum is possible or not
int subsetSum(int set[], int n, int sum)
{

    if(n == 0 and sum == 0) return 1;
    if(n == 0 and sum != 0) return 0;
    if(n != 0 and sum == 0) return 1;
    if(dp[n][sum] != -1){
        return dp[n][sum];
    }
    if(set[n-1] <= sum){
        return dp[n][sum] = subsetSum(set, n-1, sum - set[n-1]) || subsetSum(set, n-1, sum);
    }
    else{
        return dp[n][sum] = subsetSum(set, n-1, sum);
    }
}

// Driver Code
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
