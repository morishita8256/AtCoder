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

int dfs(int now, vector<bool> c, vector<vector<int>> G) {
  c[now] = true;
  int cnt_next = 0;
  int sum = 0;
  for (int next : G[now]) {
    if (c[next])
      continue;
    sum += dfs(next, c, G);
    cnt_next++;
  }
  if (cnt_next == 0) {
    bool ok = true;
    for (bool b : c) {
      if (b == false)
        ok = false;
    }
    if (ok)
      return 1;
    else
      return 0;
  }
  return sum;
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> a(M), b(M);
  vector<vector<int>> G(N);

  rep(i, M) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    G[a[i]].pb(b[i]);
    G[b[i]].pb(a[i]);
  }

  vector<bool> c(N, false);
  cout << dfs(0, c, G) << endl;
}