#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
#define bit(n) (1LL << (n))
typedef long long ll;
const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

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
  int N;
  cin >> N;
  vector<ll> x(N), y(N);
  typedef pair<ll, int> P;

  vector<P> X(N), Y(N);
  rep(i, N) {
    cin >> x[i] >> y[i];
    X[i] = mp(x[i], i);
    Y[i] = mp(y[i], i);
  }

  sort(all(X));
  sort(all(Y));

  V = N;
  E = 2 * (N - 1);
  rep(i, N - 1) {
    G.pb(edge(X[i].se, X[i + 1].se, abs(X[i].fi - X[i + 1].fi)));
    G.pb(edge(Y[i].se, Y[i + 1].se, abs(Y[i].fi - Y[i + 1].fi)));
  }

  cout << kruskal() << endl;
}