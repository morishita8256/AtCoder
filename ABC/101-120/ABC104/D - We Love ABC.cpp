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

struct mint {
  ll x;
  mint(ll x = 0) : x((x % MOD + MOD) % MOD) {}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= MOD)
      x -= MOD;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += MOD - a.x) >= MOD)
      x -= MOD;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= MOD;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res += a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res -= a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res *= a;
  }
  /* 変数名.pow(n) */
  mint pow(ll t) const {
    if (!t)
      return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1)
      a *= *this;
    return a;
  }

  // 以降はMODが素数のみ
  mint inv() const {
    return pow(MOD - 2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res /= a;
  }
};

int main() {
  string S;
  cin >> S;

  mint dp[S.size() + 1][4];
  rep(i, S.size() + 1) {
    rep(j, 4) {
      dp[i][j] = 0;
    }
  }

  dp[0][0] = 1;
  rep(i, S.size()) {
    rep(j, 4) {
      if (S[i] == '?') {
        dp[i + 1][j] += dp[i][j] * 3;
      } else {
        dp[i + 1][j] += dp[i][j];
      }
    }
    if (S[i] == 'A' || S[i] == '?') {
      dp[i + 1][1] += dp[i][0];
    }
    if (S[i] == 'B' || S[i] == '?') {
      dp[i + 1][2] += dp[i][1];
    }
    if (S[i] == 'C' || S[i] == '?') {
      dp[i + 1][3] += dp[i][2];
    }
  }
  cout << dp[S.size()][3].x << endl;
}