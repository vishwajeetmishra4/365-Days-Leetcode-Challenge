// Day 14 of 365 Days Coding Challange.(2nd Month)

// Problem number 2149-Rearrange Array Elements by Sign.

// Code Goes From Here.

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int posIdx = 0, negIdx = 1;

        for (int num : nums) {
            if (num > 0) {
                ans[posIdx] = num;
                posIdx += 2;
            } else {
                ans[negIdx] = num;
                negIdx += 2;
            }
        }

        return ans;
    }
};
