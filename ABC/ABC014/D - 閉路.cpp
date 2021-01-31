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
#pragma endregion

#pragma region LCA
template <typename G>
struct DoublingLowestCommonAncestor {
  const int LOG;
  const int root;
  vector<int> dep;
  const G& g;
  vector<vector<int>> table;

  DoublingLowestCommonAncestor(const G& g, int root)
      : g(g), dep(g.size()), LOG(32 - __builtin_clz(g.size())), root(root) {
    table.assign(LOG, vector<int>(g.size(), -1));
  }

  void dfs(int idx, int par, int d) {
    table[0][idx] = par;
    dep[idx] = d;
    for (auto& to : g[idx]) {
      if (to != par)
        dfs(to, idx, d + 1);
    }
  }

  void build() {
    dfs(root, -1, 0);
    for (int k = 0; k + 1 < LOG; k++) {
      for (int i = 0; i < table[k].size(); i++) {
        if (table[k][i] == -1)
          table[k + 1][i] = -1;
        else
          table[k + 1][i] = table[k][table[k][i]];
      }
    }
  }

  int query(int u, int v) {
    if (dep[u] > dep[v])
      swap(u, v);
    for (int i = LOG - 1; i >= 0; i--) {
      if (((dep[v] - dep[u]) >> i) & 1)
        v = table[i][v];
    }
    if (u == v)
      return u;
    for (int i = LOG - 1; i >= 0; i--) {
      if (table[i][u] != table[i][v]) {
        u = table[i][u];
        v = table[i][v];
      }
    }
    return table[0][u];
  }
};
#pragma endregion

int N;
vector<int> depth;
vector<vector<int>> Graw, G;

void dfs(int par, int cur) {
  for (int chi : Graw[cur]) {
    if (par == chi)
      continue;
    depth[chi] = depth[cur] + 1;
    G[cur].pb(chi);
    dfs(cur, chi);
  }
}

signed main() {
  cin >> N;
  vector<int> x(N - 1), y(N - 1);
  Graw = vector<vector<int>>(N);
  rep(i, N - 1) {
    cin >> x[i] >> y[i];
    x[i]--, y[i]--;
    Graw[x[i]].pb(y[i]);
    Graw[y[i]].pb(x[i]);
  }

  depth = vector<int>(N);
  G = vector<vector<int>>(N);

  dfs(-1, 0);

  DoublingLowestCommonAncestor<vector<vector<int>>> g(G, 0);
  g.build();

  int Q;
  cin >> Q;
  vector<int> a(Q), b(Q);
  rep(i, Q) {
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;
    int lca = g.query(a[i], b[i]);
    int ans = abs(depth[lca] - depth[a[i]]) + abs(depth[lca] - depth[b[i]]) + 1;
    cout << ans << endl;
  }
}