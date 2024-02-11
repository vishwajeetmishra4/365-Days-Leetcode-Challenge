//  Day 11 of 365 Days coding Challange.(2nd Month)

// Problem Number 1463-Cherry Pickup II.

// Code Goes From Here.

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return dfs(grid, dp, 0, 0, n - 1);
    }

private:
    int dfs(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int r, int c1, int c2) {
        if (r == grid.size()) return 0;
        if (c1 < 0 || c1 >= grid[0].size() || c2 < 0 || c2 >= grid[0].size()) return 0;
        if (dp[r][c1][c2] != -1) return dp[r][c1][c2];

        int cherries = grid[r][c1] + (c1 == c2 ? 0 : grid[r][c2]);
        int maxCherries = 0;
        for (int d1 = -1; d1 <= 1; ++d1) {
            for (int d2 = -1; d2 <= 1; ++d2) {
                int cherriesCurrDirection = dfs(grid, dp, r + 1, c1 + d1, c2 + d2);
                maxCherries = max(maxCherries, cherriesCurrDirection);
            }
        }
        return dp[r][c1][c2] = cherries + maxCherries;
    }
};
