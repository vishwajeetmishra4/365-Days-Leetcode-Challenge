// Day 10 of 365 Days Coding Challange.(2nd Month)

// Problem number-647-Palindromic Substrings.

// Code Goes From Here. 

class Solution{
    public:int countSubstrings(string s){int a=0;
    for(int i=0;i<s.length();++i)
    {
        a+=e(s,i,i);
        a+=e(s,i,i+1);
    }
    return a;
    }
    
    private:int e(const string&s,int l,int r)
    {
        int c=0;while(l>=0&&r<s.length()&&s[l]==s[r])
        {
            ++c;--l;++r;
        }
        return c;
    }
    };
