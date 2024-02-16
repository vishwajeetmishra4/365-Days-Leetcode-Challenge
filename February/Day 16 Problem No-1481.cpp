// Day 16 of 365 Days Coding Challange.(2nd Month)

// Problem Number 1481-Least Number of Unique integers after k removals.

// Code Goes From Here.

#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
public:
    int findLeastNumOfUniqueInts(std::vector<int>& arr, int k) {
        std::unordered_map<int, int> count;
        for (const int a : arr) {
            ++count[a];
        }

        auto cmp = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.second > b.second; // Compare frequencies in ascending order
        };
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> minHeap(cmp);

        for (const auto& [num, freq] : count) {
            minHeap.emplace(num, freq);
        }

        // Greedily remove the k least frequent numbers to have the least number of
        // unique integers.
        while (k > 0 && !minHeap.empty()) {
            k -= minHeap.top().second;
            minHeap.pop();
        }

        return minHeap.size() + (k < 0 ? 1 : 0);
    }
};
