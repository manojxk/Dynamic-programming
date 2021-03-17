#include <bits/stdc++.h>
using namespace std;
bool isSubsetSumRec(int set[], int n, int sum)
{
	if(n == 0 and sum == 0) return true;
    if(n == 0 and sum != 0) return false;
    if(n != 0 and sum == 0) return true;
    if(set[n-1] <= sum){
        return isSubsetSumRec(set, n-1, sum - set[n-1]) || isSubsetSumRec(set, n-1, sum);
    }
    else{
        return isSubsetSumRec(set, n-1, sum);
    }

}

// Driver code
int main()
{
	int set[] = { 3, 34, 4, 12, 5, 2 };
	int sum = 3;
	int n = sizeof(set) / sizeof(set[0]);
	if (isSubsetSumRec(set, n, sum) == true)
		printf("Found a subset with given sum");
	else
		printf("No subset with given sum");
	return 0;
}
