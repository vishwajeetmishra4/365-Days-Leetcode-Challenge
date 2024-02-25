// Day 24 of 365 Days Coding Challange.(2nd Month)

// Problem Number 2092-Find All People with Secrets.

// Code Goes From Here.

class UnionFind {
public:
  UnionFind(int n) : parent(n), size(n, 1) {
    iota(parent.begin(), parent.end(), 0);
  }

  int find(int u) {
    return parent[u] == u ? u : parent[u] = find(parent[u]);
  }

  void unionBySize(int u, int v) {
    int i = find(u);
    int j = find(v);
    if (i == j) return;
    if (size[i] < size[j]) swap(i, j);
    parent[j] = i;
    size[i] += size[j];
  }

  bool connected(int u, int v) {
    return find(u) == find(v);
  }

  void reset(int u) {
    parent[u] = u;
    size[u] = 1;
  }

private:
  vector<int> parent;
  vector<int> size;
};

class Solution {
public:
  vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
    vector<int> ans;
    UnionFind uf(n);
    map<int, vector<pair<int, int>>> timeToPairs;

    uf.unionBySize(0, firstPerson);

    for (const vector<int>& m : meetings)
      timeToPairs[m[2]].push_back({m[0], m[1]});

    for (const auto& [_, pairs] : timeToPairs) {
      unordered_set<int> peopleUnioned;
      for (const auto& [x, y] : pairs) {
        uf.unionBySize(x, y);
        peopleUnioned.insert(x);
        peopleUnioned.insert(y);
      }
      for (const int person : peopleUnioned)
        if (!uf.connected(person, 0))
          uf.reset(person);
    }

    for (int i = 0; i < n; ++i)
      if (uf.connected(i, 0))
        ans.push_back(i);

    return ans;
  }
};
