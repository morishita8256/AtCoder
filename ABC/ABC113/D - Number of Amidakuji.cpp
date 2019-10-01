#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(h, n) for (int h = 0; h < (n); ++h)
#define repp(h, a, b) for (int h = a; h <= (b); ++h)
#define repr(h, a, b) for (int h = a; h >= (b); --h)
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
  int H, W, K;
  cin >> H >> W >> K;
  K--;

  if (W == 1) {
    cout << 1 << endl;
    return 0;
  }

  mint dp[H + 1][W];
  rep(i, H + 1) {
    rep(j, W) {
      dp[i][j] = 0;
    }
  }

  int H_1[] = {1, 2, 3, 5, 8, 13, 21, 34};

  dp[0][0] = 1;
  repp(h, 1, H) {
    rep(k, W) {
      if (k == 0) {
        int c = H_1[W - 2];
        int r = H_1[max(0, W - 3)];
        dp[h][0] = dp[h - 1][0] * c + dp[h - 1][1] * r;
      } else if (k == W - 1) {
        int c = H_1[W - 2];
        int l = H_1[max(0, W - 3)];
        dp[h][W - 1] = dp[h - 1][W - 1] * c + dp[h - 1][W - 2] * l;
      } else {
        int c = H_1[k - 1] * H_1[W - k - 2];
        int l = H_1[max(0, k - 2)] * H_1[W - k - 2];
        int r = H_1[k - 1] * H_1[max(0, W - k - 3)];
        dp[h][k] =
            dp[h - 1][k] * c + dp[h - 1][k - 1] * l + dp[h - 1][k + 1] * r;
      }
    }
  }
  cout << dp[H][K].x << endl;
}