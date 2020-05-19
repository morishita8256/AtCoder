#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

/*
  重み付きUnionFind。
  可換群が乗る（和など）。

  WeightedUnionFind<type> uf(node, unit);
  root(x)
  weight(x)
  issame(x, y)
  diff(x, y) ... Wy - Wx
  merge(x, y, weight) ... Wx + weight = Wy
*/

#pragma region WeightedUnionFind
template <class Abel>
struct WeightedUnionFind {
  vector<int> par, rank;
  vector<Abel> diff_weight;

  WeightedUnionFind(int n = 1, Abel SUM_UNITY = 0) {
    init(n, SUM_UNITY);
  }

  void init(int n = 1, Abel SUM_UNITY = 0) {
    par.resize(n);
    rank.resize(n);
    diff_weight.resize(n);
    for (int i = 0; i < n; ++i)
      par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
  }

  int root(int x) {
    if (par[x] == x) {
      return x;
    } else {
      int r = root(par[x]);
      diff_weight[x] += diff_weight[par[x]];
      return par[x] = r;
    }
  }

  Abel weight(int x) {
    root(x);
    return diff_weight[x];
  }

  bool issame(int x, int y) {
    return root(x) == root(y);
  }

  bool merge(int x, int y, Abel w) {
    w += weight(x), w -= weight(y);
    x = root(x), y = root(y);
    if (x == y)
      return false;
    if (rank[x] < rank[y])
      swap(x, y), w = -w;
    if (rank[x] == rank[y])
      ++rank[x];
    par[y] = x;
    diff_weight[y] = w;
    return true;
  }

  Abel diff(int x, int y) {
    return weight(y) - weight(x);
  }
};
#pragma endregion WeightedUnionFind

/*
https://atcoder.jp/contests/abc087/tasks/arc090_b
*/

signed main() {
  int N, M;
  cin >> N >> M;
  vector<int> L(M), R(M), D(M);
  WeightedUnionFind<int> uf(N, 0);
  rep(i, M) {
    int L, R, D;
    cin >> L >> R >> D;
    L--, R--;

    if (uf.issame(L, R)) {
      if (uf.diff(L, R) != D) {
        cout << "No\n";
        return 0;
      }
    } else {
      uf.merge(L, R, D);
    }
  }
  cout << "Yes\n";
}