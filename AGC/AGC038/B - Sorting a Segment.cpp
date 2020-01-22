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
#define debug(var) cout << "[" << #var << "]\n" << var << "\n\n"
typedef long long ll;
const int INF = 1001001001;
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
      cout << '\n';
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


/* O(log n) */
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

signed main() {
  int N, K;
  cin >> N >> K;
  vector<int> P(N);
  rep(i, N) {
    cin >> P[i];
  }

  UnionFind UF(N - K + 1);
  vector<int> sum(N);
  rep(i, N - 1) {
    sum[i + 1] = (P[i + 1] > P[i]);
    sum[i + 1] += sum[i];
  }


  vector<int> asc_head;
  rep(i, N - K + 1) {
    if (sum[i + K - 1] - sum[i] == K - 1)
      asc_head.pb(i);
  }

  rep(i, len(asc_head) - 1) {
    UF.unite(asc_head[i], asc_head[i + 1]);
  }


  set<int> s;
  rep(i, K + 1) {
    s.insert(P[i]);
  }

  rep(i, N - K) {
    int l = P[i], r = P[i + K];
    int mn = *(s.begin()), mx = *(s.rbegin());

    if (l == mn && r == mx) {
      UF.unite(i, i + 1);
    }

    if (i == N - K - 1)
      break;
    s.erase(l);
    s.insert(P[i + K + 1]);
  }

  set<int> r;
  rep(i, N - K + 1) {
    r.insert(UF.root(i));
  }
  cout << len(r) << "\n";
}