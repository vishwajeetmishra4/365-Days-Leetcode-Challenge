// Day 17 of 365 Days Coding Challange.(2nd Month)

// Problem number 1642-Furthest Building You Can Reach.

// Code Goes From Here.

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        multiset<int> diffs;

        for (int i = 1; i < heights.size(); ++i) {
            const int diff = heights[i] - heights[i - 1];
            if (diff <= 0)
                continue;
            diffs.insert(diff);
            // If we run out of ladders, greedily use as less bricks as possible.
            if (diffs.size() > ladders) {
                bricks -= *diffs.begin();
                diffs.erase(diffs.begin());
            }
            if (bricks < 0)
                return i - 1;
        }

        return heights.size() - 1;
    }
};
