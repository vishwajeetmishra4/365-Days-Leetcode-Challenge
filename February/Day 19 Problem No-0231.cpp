// Day 19 of 365 Days Coding Challange.(2nd Month)

// Problem Number-231-Power of Two.

// Code Goes From Here. 
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};
