// Day 12 of 365 Days coding Challange.(2nd Month)

// Problem number-169-Majority Element.

// code Goes From Here.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums[0];
        int count = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == majority)
                ++count;
            else if (count == 0) {
                majority = nums[i];
                count = 1;
            } else {
                --count;
            }
        }

        return majority;
    }
};
