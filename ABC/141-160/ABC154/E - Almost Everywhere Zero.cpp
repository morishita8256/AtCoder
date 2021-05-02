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
typedef long long ll;
const int INF = 1001001001;
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

ll f(string X) {
}

signed main() {
  string n;
  cin >> n;
  int K;
  cin >> K;

  int keta = len(n);

  int N = n.size();
  vector<vector<vector<ll>>> dp(N + 1,
                                vector<vector<ll>>(2, vector<ll>(K + 1)));
  dp[0][0][0] = 1;  // [桁][未満][K] = 個数
  rep(i, N) {
    int num = n[i] - '0';
    rep(j, 2) {
      rep(k, K + 1) {
        repp(d, 0, j ? 9 : num) {
          if (d != 0) {
            if (k + 1 > K)
              continue;
            else
              dp[i + 1][j | d < num][k + 1] += dp[i][j][k];
          } else
            dp[i + 1][j | d < num][k] += dp[i][j][k];
        }
      }
    }
  }
  ll ans = dp[N][1][K] + dp[N][0][K];
  cout << ans << endl;
}