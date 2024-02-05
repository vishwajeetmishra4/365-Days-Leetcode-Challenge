// Day 5 of 365 Days Coding Challange.(2nd Month)

// Problem Number 0387-First Unique Chracter in a String.

// Code Goes From Here.

class Solution {
 public:
  int firstUniqChar(string s) {
    vector<int> count(26);

    for (const char c : s)
      ++count[c - 'a'];

    for (int i = 0; i < s.length(); ++i)
      if (count[s[i] - 'a'] == 1)
        return i;

    return -1;
  }
};
