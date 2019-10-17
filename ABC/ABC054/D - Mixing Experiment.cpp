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
  int N, Ma, Mb;
  cin >> N >> Ma >> Mb;
  vector<int> a(N), b(N), c(N);
  rep(i, N) cin >> a[i] >> b[i] >> c[i];
  vector<vector<vector<int>>> cost(
      N + 1, vector<vector<int>>(401, vector<int>(401, INF)));
  cost[0][0][0] = 0;
  rep(n, N) {
    rep(i, 400) {
      rep(j, 400) {
        if (cost[n][i][j] == INF)
          continue;

        // not use
        chmin(cost[n + 1][i][j], cost[n][i][j]);

        // use
        if (i + a[n] > 400 || j + b[n] > 400)
          continue;
        chmin(cost[n + 1][i + a[n]][j + b[n]], cost[n][i][j] + c[n]);
      }
    }
  }

  int ans = INF;
  repp(i, 1, 400) {
    repp(j, 1, 400) {
      if (abs(((double)i / (double)j) - ((double)Ma / (double)Mb)) < 1e-5)
        chmin(ans, cost[N][i][j]);
    }
  }
  if (ans == INF)
    ans = -1;

  cout << ans << endl;
}