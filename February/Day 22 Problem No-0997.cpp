// Day 22 of 365 Days Coding Challange.(2nd Month)

// Problem Number 997- Find the Town Judge.

// Code Goes From Here.

class Solution {
 public:
  int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> count(n + 1);

    for (vector<int>& t : trust) {
      --count[t[0]];
      ++count[t[1]];
    }

    for (int i = 1; i < n + 1; ++i)
      if (count[i] == n - 1)
        return i;

    return -1;
  }
};
