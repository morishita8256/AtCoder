#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
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

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> X(M), Y(M), Z(M);
  UnionFind U(N);
  rep(i, M) {
    cin >> X[i] >> Y[i] >> Z[i];
    X[i]--;
    Y[i]--;
    U.unite(X[i], Y[i]);
  }

  set<int> s;
  rep(i, N) {
    int r = U.root(i);
      s.insert(r);
  }
  cout << s.size() << endl;
}