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

void dfs(int now, vector<vector<int>> G, vector<bool> &connected) {
  connected[now] = true;
  for (auto next : G[now]) {
    if (connected[next] == false) {
      dfs(next, G, connected);
    }
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> a(M), b(M);
  rep(i, M) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }

  int ans = 0;
  rep(m, M) {
    vector<vector<int>> G(N);
    rep(i, M) {
      if (i == m)
        continue;
      G[a[i]].pb(b[i]);
      G[b[i]].pb(a[i]);
    }

    vector<bool> connected(N, false);
    dfs(0, G, connected);

    int con = true;
    rep(i, N) {
      if (connected[i] == false)
        con = false;
    }

    if (!con)
      ans++;
  }
  cout << ans << endl;
}