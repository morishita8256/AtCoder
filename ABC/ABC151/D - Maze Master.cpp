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
  int H, W;
  cin >> H >> W;
  vector<vector<char>> S(H, vector<char>(W));
  rep(i, H) {
    rep(j, W) {
      cin >> S[i][j];
    }
  }

  int V;
  V = H * W;

  vector<vector<ll>> dist(V, vector<ll>(V, INF));
  rep(i, V) {
    dist[i][i] = 0;
  }

  rep(i, H) {
    rep(j, W) {
      if (j + 1 < W && S[i][j] == '.' && S[i][j + 1] == '.') {
        dist[i * W + j][i * W + (j + 1)] = 1;
        dist[i * W + (j + 1)][i * W + j] = 1;
      }
      if (i + 1 < H && S[i][j] == '.' && S[i + 1][j] == '.') {
        dist[i * W + j][(i + 1) * W + j] = 1;
        dist[(i + 1) * W + j][i * W + j] = 1;
      }
    }
  }

  warshal_floyd(dist);

  ll ans = 0;
  rep(i, V) {
    rep(j, V) {
      if (dist[i][j] >= INF)
        continue;
      chmax(ans, dist[i][j]);
    }
  }
  cout << ans << endl;
}