// Day 9 of 365 Days Coding Challange.(2nd Month)

// Problem Number 368- Largest Division Subset.

// Code Goes From Here .

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> largestDivisibleSubset(std::vector<int>& nums) {
        int n = nums.size(), maxSize = 0, maxIndex = -1;
        std::vector<int> dp(n, 1), prev(n, -1), ans;

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (maxSize < dp[i]) {
                maxSize = dp[i];
                maxIndex = i;
            }
        }

        while (maxIndex != -1) {
            ans.push_back(nums[maxIndex]);
            maxIndex = prev[maxIndex];
        }

        return ans;
    }
};
