//Day 2 of 365 Days Challenge.

//Problem number 2610- Convcert an Array into a 2D Array with Conditions.

// Code Goes from Here

class Solution {
 public:
  vector<vector<int>> findMatrix(vector<int>& nums) {
    // The number of rows we need equals the maximum frequency.
    vector<vector<int>> ans;
    vector<int> count(nums.size() + 1);

    for (const int num : nums) {
      // Construct `ans` on demand.
      if (++count[num] > ans.size())
        ans.push_back({});
      ans[count[num] - 1].push_back(num);
    }

    return ans;
  }
};