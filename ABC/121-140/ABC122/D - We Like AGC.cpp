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

/* mint、表示は変数名.x */
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
  mint inv() const { return pow(MOD - 2); }
  mint& operator/=(const mint a) { return (*this) *= a.inv(); }
  mint operator/(const mint a) const {
    mint res(*this);
    return res /= a;
  }
};

int main() {
  int N;
  cin >> N;

  mint dp[N + 1][5][5][5]; /* 0-dummy, 1-A, 2-C, 3-G, 4-T */
  rep(n, N + 1) {
    rep(i, 5) {
      rep(j, 5) {
        rep(k, 5) { dp[n][i][j][k] = 0; }
      }
    }
  }
  dp[0][0][0][0] = 1;

  rep(n, N) {
    rep(i, 5) {
      rep(j, 5) {
        rep(k, 5) {
          repp(l, 1, 4) {
            if (j == 1 && k == 2 && l == 3)
              continue;
            if (j == 1 && k == 3 && l == 2)
              continue;
            if (j == 3 && k == 1 && l == 2)
              continue;
            if (i == 1 && j == 3 && l == 2)
              continue;
            if (i == 1 && k == 3 && l == 2)
              continue;
            dp[n + 1][j][k][l] += dp[n][i][j][k];
          }
        }
      }
    }
  }

  mint ans = 0;

  repp(i, 1, 4) {
    repp(j, 1, 4) {
      repp(k, 1, 4) { ans += dp[N][i][j][k]; }
    }
  }
  cout << ans.x << endl;
}