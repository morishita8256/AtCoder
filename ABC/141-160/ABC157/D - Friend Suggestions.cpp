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
  int N, M, K;
  cin >> N >> M >> K;
  vector<int> A(M), B(M);
  rep(i, M) {
    cin >> A[i] >> B[i];
    A[i]--, B[i]--;
  }
  vector<int> C(K), D(K);
  rep(i, K) {
    cin >> C[i] >> D[i];
    C[i]--, D[i]--;
  }

  vector<int> friends(N);
  rep(i, M) {
    friends[A[i]]++, friends[B[i]]++;
  }

  UnionFind u(N);
  rep(i, M) {
    u.unite(A[i], B[i]);
  }

  vector<int> size(N);
  rep(i, N) {
    size[u.root(i)]++;
  }

  vector<bool> valid_block(K, true);
  rep(i, K) {
    if (u.root(C[i]) != u.root(D[i]))
      valid_block[i] = false;
  }

  vector<int> block(N);
  rep(i, K) {
    if (!valid_block[i])
      continue;
    block[C[i]]++, block[D[i]]++;
  }

  vector<int> ans(N);
  rep(i, N) {
    ans[i] = size[u.root(i)] - friends[i] - block[i] - 1;
  }
  cout << ans << endl;
}