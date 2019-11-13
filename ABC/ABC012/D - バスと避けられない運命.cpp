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
#define sz(x) ((ll)(x).size())
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


void warshal_floyd(vector<vector<ll>>& dist) {
  int V = dist.size();
  rep(k, V) {
    rep(i, V) {
      rep(j, V) {
        // 負の辺のために必要なif文
        if (dist[i][k] != LINF && dist[k][j] != LINF)
          chmin(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
}


int main() {
  int N, M;
  cin >> N >> M;
  vector<int> a(M), b(M), t(M);
  rep(i, M) {
    cin >> a[i] >> b[i] >> t[i];
    a[i]--, b[i]--;
  }

  int V, E;
  V = N, E = M;

  vector<vector<ll>> dist(V, vector<ll>(V, LINF));
  rep(i, V) {
    dist[i][i] = 0;
  }
  rep(i, E) {
    ll from, to, cost;
    from = a[i], to = b[i], cost = t[i];
    dist[from][to] = cost;
    dist[to][from] = cost;
  }

  warshal_floyd(dist);

  ll ans = LINF;
  rep(i, N) {
    ll temp = 0;
    rep(j, N) {
      chmax(temp, dist[i][j]);
    }
    chmin(ans, temp);
  }
  cout << ans << endl;
}