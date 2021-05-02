#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
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

int main() {
  ll N, M;
  cin >> N >> M;
  vector<ll> A(M), B(M);
  rep(i, M) {
    cin >> A[i] >> B[i];
    A[i]--;
    B[i]--;
  }

  reverse(all(A));
  reverse(all(B));

  UnionFind u(N);
  vector<ll> inconv(M);
  inconv[0] = N * (N - 1) / 2;
  repp(i, 1, M - 1) {
    int a = A[i - 1], b = B[i - 1];
    if (u.issame(a, b)) {
      inconv[i] = inconv[i - 1];
    } else {
      inconv[i] = inconv[i - 1] - u.size(a) * u.size(b);
      u.unite(a, b);
    }
  }

  reverse(all(inconv));
  rep(i, M) {
    cout << inconv[i] << endl;
  }
}