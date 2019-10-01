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
const int MOD = 1e9 + 7;

int main() {
  int n, score;
  cin >> n >> score;

  vector<vector<vector<ll>>> dp(55, vector<vector<ll>>(55, vector<ll>(2605)));

  dp[0][0][0] = 1;

  repp(i, 0, n - 1) {
    repp(j, 0, i) {
      repp(k, 0, score + 1) {
        dp[i + 1][j][k + 2 * j] += dp[i][j][k];
        dp[i + 1][j][k + 2 * j] %= MOD;
        dp[i + 1][j + 1][k + 2 * (j + 1)] += dp[i][j][k];
        dp[i + 1][j + 1][k + 2 * (j + 1)] %= MOD;
        dp[i + 1][j][k + 2 * j] += dp[i][j][k] * 2 * j;
        dp[i + 1][j][k + 2 * j] %= MOD;
        if (j > 0) {
          dp[i + 1][j - 1][k + 2 * (j - 1)] += dp[i][j][k] * j * j;
          dp[i + 1][j - 1][k + 2 * (j - 1)] %= MOD;
        }
      }
    }
  }
  cout << dp[n][0][score] << endl;
}