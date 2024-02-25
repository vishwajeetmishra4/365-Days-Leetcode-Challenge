// Day 25 of 365 Days Coding Challange.(2nd Month)

// Problem Number 2709- Greatest Common Divisor Traversal.

// Code Goes From Here.
\#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class UnionFind {
public:
    UnionFind(int n) : parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    void unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return;
        if (size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];
    }

    int getSize(int u) {
        return size[find(u)];
    }

private:
    vector<int> parent;
    vector<int> size;

    int find(int u) {
        return parent[u] == u ? u : parent[u] = find(parent[u]);
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        int maxNum = *max_element(nums.begin(), nums.end());
        vector<int> minPrimeFactors = sieveEratosthenes(maxNum + 1);
        unordered_map<int, int> primeToFirstIndex;
        UnionFind uf(n);

        for (int i = 0; i < n; ++i) {
            for (int primeFactor : getPrimeFactors(nums[i], minPrimeFactors)) {
                if (primeToFirstIndex.count(primeFactor)) {
                    uf.unite(primeToFirstIndex[primeFactor], i);
                } else {
                    primeToFirstIndex[primeFactor] = i;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (uf.getSize(i) == n) {
                return true;
            }
        }

        return false;
    }

private:
    vector<int> sieveEratosthenes(int n) {
        vector<int> minPrimeFactors(n + 1);
        iota(minPrimeFactors.begin(), minPrimeFactors.end(), 0);
        for (int i = 2; i * i < n; ++i) {
            if (minPrimeFactors[i] == i) {
                for (int j = i * i; j < n; j += i) {
                    if (minPrimeFactors[j] == j) {
                        minPrimeFactors[j] = i;
                    }
                }
            }
        }
        return minPrimeFactors;
    }

    vector<int> getPrimeFactors(int num, const vector<int>& minPrimeFactors) {
        vector<int> factors;
        while (num > 1) {
            int divisor = minPrimeFactors[num];
            factors.push_back(divisor);
            while (num % divisor == 0) num /= divisor;
        }
        return factors;
    }
};
