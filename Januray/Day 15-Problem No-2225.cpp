// Day 15 of 365 Days coding Challenge.

// Problem No. 2225. Find Players With Zero or One Losses.

//Code Goes From Here.

class Solution {
 public:
  vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    vector<vector<int>> ans(2);
    map<int, int> lossesCount;

    for (const vector<int>& m : matches) {
      const int winner = m[0];
      const int loser = m[1];
      if (!lossesCount.count(winner))
        lossesCount[winner] = 0;
      ++lossesCount[loser];
    }

    for (const auto& [player, nLosses] : lossesCount)
      if (nLosses < 2)
        ans[nLosses].push_back(player);

    return ans;
  }
};
