// Day 19 of 365 days Coding Challange.

// Problem number 0931-Minimum Falling Path SUM.

// Code Goes From here.

class Solution {
 public:
  int minFallingPathSum(vector<vector<int>>& A) {
    const int n = A.size();

    for (int i = 1; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        int mini = INT_MAX;
        for (int k = max(0, j - 1); k < min(n, j + 2); ++k)
          mini = min(mini, A[i - 1][k]);
        A[i][j] += mini;
      }

    return ranges::min(A[n - 1]);
  }
};
