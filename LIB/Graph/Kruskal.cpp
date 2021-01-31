#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LINF = 1001001001001001001ll;

/*
edgeはedge<type>(from, to, d)で与える。
グラフはvector<edge>で与える。
*/

#pragma region Kruskal
struct UnionFind {
  vector<int> parent;  // parent[root] is the negative of the size.
  UnionFind(int n) : parent(n, -1){};
  bool unite(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v)
      return false;
    if (parent[u] > parent[v])
      swap(u, v);
    parent[u] += parent[v];
    parent[v] = u;
    return true;
  }
  bool issame(int u, int v) {
    return root(u) == root(v);
  }
  int root(int u) {
    return parent[u] < 0 ? u : parent[u] = root(parent[u]);
  }
  int size(int u) {
    return -parent[root(u)];
  }
};

/*
  edge(from, to, cost)
  not directed
*/
template <typename T>
struct edge {
  int from, to;
  T cost;

  edge(int from, int to, T cost) : from(from), to(to), cost(cost) {
  }

  bool operator<(const edge& o) const {
    return cost < o.cost;
  }
};


/* O(E log V) */
template <typename T>
T Kruskal(vector<edge<T>>& G, int V) {
  sort(G.begin(), G.end());
  int E = G.size();
  UnionFind uf(V);
  T min_cost = 0;

  for (int ei = 0; ei < E; ei++) {
    edge<T> e = G[ei];
    if (!uf.issame(e.from, e.to)) {
      min_cost += e.cost;
      uf.unite(e.from, e.to);
    }
  }

  return min_cost;
}
#pragma endregion Kruskal


/*
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=ja
*/

int main() {
  int V, E;
  cin >> V >> E;

  vector<edge<int>> G;
  for (int i = 0; i < E; i++) {
    int s, t, w;
    cin >> s >> t >> w;
    G.push_back(edge<int>(s, t, w));
  }

  cout << Kruskal(G, V) << endl;
}