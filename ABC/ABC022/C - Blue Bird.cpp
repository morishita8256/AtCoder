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
#define sz(x) ((int)(x).size())
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

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> u(M), v(M), l(M);
  vector<vector<ll>> d(N, vector<ll>(N, LINF));
  typedef pair<int, ll> P;
  rep(i, N) {
    d[i][i] = 0;
  }

  vector<P> adj;
  rep(i, M) {
    cin >> u[i] >> v[i] >> l[i];
    u[i]--;
    v[i]--;
    if (u[i] == 0)
      adj.pb(P(v[i], l[i]));
    else {
      d[u[i]][v[i]] = l[i];
      d[v[i]][u[i]] = l[i];
    }
  }

  for (int k = 0; k < N; k++) {      // 経由する頂点
    for (int i = 0; i < N; i++) {    // 始点
      for (int j = 0; j < N; j++) {  // 終点
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  ll ans = LINF;
  int num = sz(adj);
  repp(i, 0, num - 1) {
    repp(j, i + 1, num - 1) {
      int s = adj[i].fi;
      int t = adj[j].fi;

      ll dist = adj[i].se + adj[j].se;
      if (d[s][t] == LINF)
        continue;
      dist += d[s][t];

      chmin(ans, dist);
    }
  }
  if (ans == LINF)
    cout << -1 << endl;
  else
    cout << ans << endl;
}