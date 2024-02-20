// Day 20 of 365 Days Coding challange.(2nd Month)

// Problem number 268-Missing Number.

// Code Goes From Here 

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int total = (n * (n + 1)) / 2;
        return total - sum;
    }
};
