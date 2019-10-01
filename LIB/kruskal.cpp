#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LINF = 1001001001001001001ll;

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

struct edge {
  int from, to;
  ll cost;

  edge(int from, int to, ll cost) : from(from), to(to), cost(cost) {}

  bool operator<(const edge& o) const {
    return cost < o.cost;
  }
};

int V, E;
vector<edge> G;

/* O(E log V) */
ll kruskal() {
  sort(G.begin(), G.end());

  UnionFind uf(V);
  ll min_cost = 0;

  for (int ei = 0; ei < E; ei++) {
    edge e = G[ei];
    if (!uf.issame(e.from, e.to)) {
      min_cost += e.cost;
      uf.unite(e.from, e.to);
    }
  }

  return min_cost;
}

int main() {
  cin >> V >> E;

  for (int i = 0; i < E; i++) {
    ll from, to, cost;
    cin >> from >> to >> cost;
    G.push_back(edge(from, to, cost));
  }

  cout << kruskal() << endl;
}