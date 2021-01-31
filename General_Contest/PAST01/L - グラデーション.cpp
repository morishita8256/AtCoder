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
#define int long long
typedef long long ll;
const int INF = 1001001001001001001ll;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;
const double EPS = 1e-9;

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

double dist(double x, double y, double xx, double yy) {
  return sqrt(pow(x - xx, 2) + pow(y - yy, 2));
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
  double cost;

  edge(int from, int to, double cost) : from(from), to(to), cost(cost) {
  }

  bool operator<(const edge& o) const {
    return cost < o.cost;
  }
};

/* O(E log V) */
double kruskal(vector<edge>& G, int V, int E) {
  sort(G.begin(), G.end());

  UnionFind uf(V);
  double min_cost = 0;

  for (int ei = 0; ei < E; ei++) {
    edge e = G[ei];
    if (!uf.issame(e.from, e.to)) {
      min_cost += e.cost;
      uf.unite(e.from, e.to);
    }
  }

  return min_cost;
}

signed main() {
  int N, M;
  cin >> N >> M;
  vector<double> x(N), y(N);
  vector<int> c(N);
  rep(i, N) {
    cin >> x[i] >> y[i] >> c[i];
  }

  vector<double> X(M), Y(M);
  vector<int> C(M);
  rep(i, M) {
    cin >> X[i] >> Y[i] >> C[i];
  }

  double ans = INF;
  rep(b, bit(M)) {
    auto XX = x;
    auto YY = y;
    auto CC = c;

    rep(i, M) {
      if ((b >> i) & 1) {
        XX.pb(X[i]);
        YY.pb(Y[i]);
        CC.pb(C[i]);
      }
    }

    int V = len(XX);
    int E = V * (V - 1) / 2;
    vector<edge> G;

    rep(i, V) {
      repp(j, i + 1, V - 1) {
        double cost = dist(XX[i], YY[i], XX[j], YY[j]);
        if (CC[i] != CC[j])
          cost *= 10;
        G.pb(edge(i, j, cost));
      }
    }

    double temp = kruskal(G, V, E);
    chmin(ans, temp);
  }
  cout << ans << endl;
}