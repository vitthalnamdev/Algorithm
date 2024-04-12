#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Disjoint-set data structure using path compression and union by rank
struct DisjointSet {
  vector<int> parent, rank;

  DisjointSet(int n) {
    parent.resize(n);
    rank.resize(n, 0);
    for (int i = 0; i < n; ++i) {
      parent[i] = i;
    }
  }

  int find(int u) {
    if (u != parent[u]) {
      parent[u] = find(parent[u]); // Path compression
    }
    return parent[u];
  }

  void Union(int u, int v) {
    int root_u = find(u), root_v = find(v);
    if (root_u == root_v) return;
    if (rank[root_u] < rank[root_v]) {
      parent[root_u] = root_v;
    } else if (rank[root_u] > rank[root_v]) {
      parent[root_v] = root_u;
    } else {
      parent[root_v] = root_u;
      rank[root_u]++;
    }
  }
};

int main() {
  int N;
  cin >> N;

  // Grid to represent the infinite 2D field
  vector<vector<bool>> grid(1001, vector<bool>(1001, true));

  // Information about each cow
  vector<tuple<int, int, int, string>> cows;

  for (int i = 0; i < N; ++i) {
    string direction;
    int x, y;
    cin >> direction >> x >> y;

    grid[y][x] = false; // Mark starting cell as eaten

    int stopped_count = 0;
    cows.push_back({x, y, stopped_count, direction});
  }

  // Disjoint-set to track connected components of eaten cells
  DisjointSet ds(N * 1001);

  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};

  while (true) {
    bool all_stopped = true;
    for (int i = 0; i < N; ++i) {
      int x = get(cows[i]);
      int y = get(cows[i]);
      int stopped_count = get(cows[i]);
      string direction = get(cows[i]);

      if (direction == "N") {
        int nx = x, ny = y + 1;
        if (0 <= ny && ny < 1001 && grid[ny][nx]) {
          grid[ny][nx] = false;
          int root_new = ds.find(ny * 1001 + nx);
          if (root_new != i * 1001 + x) {
            ds.Union(i * 1001 + x, root_new);
            if (cows[ds.find(root_new)][3] != "X") {
              stopped_count++;
              cows[ds.find(root_new)][2] = cows[ds.find(root_new)][2] + 1;
            }
          }
          cows[i] = {nx, ny, stopped_count, direction};
          all_stopped = false;
        } else {
          cows[i] = {x, y, stopped_count, "X"}; // Cow stops grazing
        }
      } else if (direction == "E") {
        int nx = x + 1, ny = y;
        if (0 <= nx && nx < 1001 && grid[ny][nx]) {
          grid[ny][nx] = false;
          int root_new = ds.find(ny * 1001 + nx);
          if (root_new != i * 1001 + x) {
            ds.Union(i * 1001 + x, root_new);
            if (cows[ds.find(root_new)][3] != "X") {
              stopped_count++;```
