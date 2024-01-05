//Day 1 of 365 Days Challenge.

//Problem number 455. Assign Cookies.

// Code Goes from Here

class Solution {
 public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    ranges::sort(g);
    ranges::sort(s);

    int i = 0;
    for (int j = 0; j < s.size() && i < g.size(); ++j)
      if (g[i] <= s[j])
        ++i;

    return i;
  }
};