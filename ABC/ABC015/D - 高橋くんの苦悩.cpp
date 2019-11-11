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

int main() {
  int W;
  cin >> W;
  int N, K;
  cin >> N >> K;
  vector<int> A(N), B(N);
  rep(i, N) {
    cin >> A[i] >> B[i];
  }

  // dp[checked num][used num][width] = inportance
  vector<vector<vector<int>>> dp(
      N + 1, vector<vector<int>>(K + 1, vector<int>(W + 1, -1)));
  dp[0][0][0] = 0;

  rep(i, N) {
    rep(j, K+1) {
      rep(k, W+1) {
        int now = dp[i][j][k];
        if (now == -1)
          continue;

        // use
        if (k + A[i] <= W && j + 1 <= K)
          chmax(dp[i + 1][j + 1][k + A[i]], now + B[i]);

        // not use
        chmax(dp[i + 1][j][k], now);
      }
    }
  }

  int ans = 0;
  rep(j, K + 1) {
    rep(k, W + 1) {
      chmax(ans, dp[N][j][k]);
    }
  }
  cout << ans << endl;
}