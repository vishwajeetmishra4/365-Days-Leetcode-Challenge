//Day 13 of 365 Days Challenge.

//Problem number 1347. Minimum Number of Steps to make 2 string Anagram.

//Code Goes from Here.

class Solution {
 public:
  int minSteps(string s, string t) {
    vector<int> count(26);

    for (const char c : s)
      ++count[c - 'a'];

    for (const char c : t)
      --count[c - 'a'];

    return accumulate(count.begin(), count.end(), 0,
                      [](int subtotal, int c) { return subtotal + abs(c); }) /
           2;
  }
};
