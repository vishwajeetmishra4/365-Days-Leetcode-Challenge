// Day 21 of 365 Days Coding Challange.(2nd Month)

// Problem Number 201-Bitwise AND of Number Range.

// Code Goes From Here.

class Solution {
 public:
  int rangeBitwiseAnd(int m, int n) {
    int shiftBits = 0;

    while (m != n) {
      m >>= 1;
      n >>= 1;
      ++shiftBits;
    }

    return m << shiftBits;
  }
};
