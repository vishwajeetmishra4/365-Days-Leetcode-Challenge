// Day 31 of  365 Days Coding Challange.

// Problem Number 739-Daily Temerature.

// Code Goes From Here.

class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> ans(temperatures.size());
    stack<int> stack;  // a decreasing stack

    for (int i = 0; i < temperatures.size(); ++i) {
      while (!stack.empty() && temperatures[stack.top()] < temperatures[i]) {
        const int index = stack.top();
        stack.pop();
        ans[index] = i - index;
      }
      stack.push(i);
    }

    return ans;
  }
};
