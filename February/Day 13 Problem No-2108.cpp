// Day 13 of 365 Days Coding Challange.(2nd Month)

// Problem Number 2108-Find First Palindromic String in array Submissions.

// Code Goes From Here.

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (const string& word : words) {
            if (isPalindrome(word)) {
                return word;
            }
        }
        return "";
    }

private:
    bool isPalindrome(const string& s) {
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }
};
