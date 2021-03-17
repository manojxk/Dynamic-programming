
#include <bits/stdc++.h>
using namespace std;
int knapSack(int W, int wt[], int val[], int n)
{
    //Base case
    if(n == 0 || W == 0) return 0;
    //Choice diagram
    /*if wt[n-1] <= W
             /\
      Select    Not Select
      if wt[n-1] > W
           |
        Not Select
    */
   if(wt[n-1] <= W)
        return max(val[n-1] + knapSack(W-wt[n-1],wt,val,n-1), knapSack(W,wt,val,n-1));
   else 
        return knapSack(W,wt,val,n-1);

}

int main()
{
	int val[] = { 60, 100, 120 };
	int wt[] = { 10, 20, 30 };
	int W = 50;
	int n = sizeof(val) / sizeof(val[0]);
	cout << knapSack(W, wt, val, n);
	return 0;
}