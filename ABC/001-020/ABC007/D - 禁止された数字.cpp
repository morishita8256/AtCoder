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

ll f(string X) {
  int N = X.size();
  vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>>(2, vector<ll>(2)));
  dp[0][0][0] = 1;  // [桁][未満][4,9使用]
  rep(i, N) {
    int num = X[i] - '0';
    rep(j, 2) {
      rep(k, 2) {
        repp(d, 0, j ? 9 : num) {
          dp[i + 1][j | d < num][k || d == 4 || d == 9] += dp[i][j][k];
        }
      }
    }
  }
  return dp[N][1][1] + dp[N][0][1];
}

int main() {
  ll A, B;
  cin >> A >> B;
  A--;
  string a = to_string(A);
  string b = to_string(B);
  cout << f(b) - f(a) << endl;
}