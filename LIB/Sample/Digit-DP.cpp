#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define len(x) ((ll)(x).size())
typedef long long ll;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;


struct mint {
  ll x;
  mint(ll x = 0) : x((x % MOD + MOD) % MOD) {
  }
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

ostream& operator<<(ostream& s, const mint a) {
  s << a.x;
  return s;
}

/* a^n (MOD) の計算 O(log n) */
ll modpow(ll a, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1)
      res = res * a % MOD;
    a = a * a % MOD;
    n >>= 1;
  }
  return res;
}

// a^{-1} mod を計算する
ll modinv(ll a) {
  return modpow(a, MOD - 2);
}

/*
https://tdpc.contest.atcoder.jp/tasks/tdpc_number
制約:桁和がDの倍数
*/

signed main() {
  int D;
  cin >> D;
  string S;
  cin >> S;

  vector<int> A;
  for (auto c : S) {
    A.pb(c - '0');
  }

  int N = len(A);


  vector<vector<vector<mint>>> dp(N + 1,
                                  vector<vector<mint>>(2, vector<mint>(D)));
  dp[0][0][0] = 1;  // [桁][未満][mod]
  rep(n, N) {
    int num = A[n];
    rep(s, 2) {  // smaller flag
      rep(k, D) {
        repp(next, 0, s ? 9 : num) {
          dp[n + 1][s | next < num][(k + next) % D] += dp[n][s][k];
        }
      }
    }
  }
  mint ans = dp[N][1][0] + dp[N][0][0];
  cout << (ans - 1) << endl;  // 0を除外
}