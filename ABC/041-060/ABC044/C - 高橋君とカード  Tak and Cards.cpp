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

int main() {
  ll N, A;
  cin >> N >> A;
  vector<ll> x(N);
  rep(i, N) {
    cin >> x[i];
  }

  vector<vector<vector<ll>>> dp(
      N + 1, vector<vector<ll>>(N + 1, vector<ll>(N * 50 + 1)));

  dp[0][0][0] = 1;

  rep(i, N) {
    rep(j, N + 1) {
      rep(k, N * 50 + 1) {
        if (j < N && k + x[i] <= N * 50)
          dp[i + 1][j + 1][k + x[i]] += dp[i][j][k];
        dp[i + 1][j][k] += dp[i][j][k];
      }
    }
  }

  ll ans = 0;
  repp(j, 1, N) {
    ans += dp[N][j][j * A];
  }

  cout << ans << endl;
}