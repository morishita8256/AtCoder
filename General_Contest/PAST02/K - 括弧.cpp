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
#define len(x) ((ll)(x).size())
#define debug(var) cout << "[" << #var << "]\n" << var << endl
#define int long long
typedef long long ll;
const int INF = 1001001001001001001ll;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;
const double EPS = 1e-9;

template <typename T>
ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    s << v[i];
    if (i < len - 1)
      s << ' ';
  }
  return s;
}

template <typename T>
ostream& operator<<(ostream& s, const vector<vector<T>>& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) {
    s << vv[i];
    if (i != len - 1)
      s << '\n';
  }
  return s;
}

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

__attribute__((constructor)) void initial() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
}

signed main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  vector<int> C(N);
  rep(i, N) {
    cin >> C[i];
  }
  vector<int> D(N);
  rep(i, N) {
    cin >> D[i];
  }

  // dp[n文字][余っている'('の数]
  vector<vector<int>> dp(N + 1, vector<int>(N, INF));
  dp[0][0] = 0;
  rep(i, N) {
    char c = S[i];
    rep(j, N) {
      if (dp[i][j] == INF)
        continue;

      if (c == '(') {
        // no touch
        chmin(dp[i + 1][j + 1], dp[i][j]);

        // reverse
        if (j > 0)
          chmin(dp[i + 1][j - 1], dp[i][j] + C[i]);


        // erase
        chmin(dp[i + 1][j], dp[i][j] + D[i]);

      } else if (c == ')') {
        // no touch
        if (j > 0)
          chmin(dp[i + 1][j - 1], dp[i][j]);

        // reverse
        chmin(dp[i + 1][j + 1], dp[i][j] + C[i]);

        // erase
        chmin(dp[i + 1][j], dp[i][j] + D[i]);
      }
    }
  }
  int ans = dp[N][0];
  cout << ans << endl;
}