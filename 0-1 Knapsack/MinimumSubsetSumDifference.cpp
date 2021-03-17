
#include <bits/stdc++.h>
using namespace std;

int dp[2000][2000];

vector<int> minPartition(int set[], int n, int sum)
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
    vector<int> v;
    for(int i = 0; i <= sum/2; i++){
        if(dp[n][i])
        v.push_back(i);
    }
    
    return v;
}

int main()
{
	// Storing the value -1 to the matrix
	memset(dp, -1, sizeof(dp));
	int n = 6;
	int a[] = {3, 1, 4, 2, 2, 1};;
	int sum = accumulate(a,a+6,0);
    vector<int> v = minPartition(a, n, sum);
    int mn = INT_MAX;
    for(int i = 0; i < v.size(); i++)
    {
        mn = min(mn, sum - 2*v[i]);
    }
    cout<<mn<<endl;

	
}

