#pragma region head
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
#define len(x) ((ll)(x).size())
#define debug(var) cout << "[" << #var << "]\n" << var << endl
#define test(s) \
  if (!(s))     \
    cout << "Line " << __LINE__ << ": [" << #s << "] is false" << endl;
#define int long long
typedef long long ll;
#define double long double
typedef double ld;
const int INF = 1001001001001001001ll;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;
const double EPS = 1e-9;
const double PI = acos(-1.0);

template <typename T>
ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    s << v[i];
    if (i < len - 1)
      s << ' ';
  }
  return s;
}

template <typename T>
ostream& operator<<(ostream& s, const vector<vector<T>>& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) {
    s << vv[i];
    if (i != len - 1)
      s << '\n';
  }
  return s;
}

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

__attribute__((constructor)) void initial() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
}
#pragma endregion

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


int c(int x1, int y1, int x2, int y2) {
  return min(abs(x2 - x1), abs(y2 - y1));
}

struct city {
  ll id, x, y;
  city() = default;
  city(ll id, ll x, ll y) : id(id), x(x), y(y) {
  }
};

bool sort_by_x(const city& l, const city& r) {
  return l.x < r.x;
}

bool sort_by_y(const city& l, const city& r) {
  return l.y < r.y;
}


signed main() {
  int N;
  cin >> N;
  vector<int> x(N), y(N);
  rep(i, N) {
    cin >> x[i] >> y[i];
  }

  vector<city> citys(N);
  rep(i, N) {
    citys[i].id = i;
    citys[i].x = x[i];
    citys[i].y = y[i];
  }

  sort(all(citys), sort_by_x);

  vector<edge<int>> G;

  rep(i, N - 1) {
    auto c1 = citys[i], c2 = citys[i + 1];
    G.pb(edge<int>(c1.id, c2.id, abs(c1.x - c2.x)));
  }

  sort(all(citys), sort_by_y);

  rep(i, N - 1) {
    auto c1 = citys[i], c2 = citys[i + 1];
    G.pb(edge<int>(c1.id, c2.id, abs(c1.y - c2.y)));
  }

  int ans = Kruskal(G, N);
  cout << ans << endl;
}