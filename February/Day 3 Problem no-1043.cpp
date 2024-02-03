// Day 3 of 365 Days Coding Challange.(2nd Month)

// Problem number 1043-Partition Array for Maximum Sum.

// Code Goes From Here.

class Solution {
 public:
  int maxSumAfterPartitioning(vector<int>& arr, int k) {
    const int n = arr.size();
    vector<int> dp(n + 1);

    for (int i = 1; i <= n; ++i) {
      int maxi = INT_MIN;
      for (int j = 1; j <= min(i, k); ++j) {
        maxi = max(maxi, arr[i - j]);
        dp[i] = max(dp[i], dp[i - j] + maxi * j);
      }
    }

    return dp[n];
  }
};
