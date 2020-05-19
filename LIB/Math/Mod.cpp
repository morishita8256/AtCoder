#include <bits/stdc++.h>
typedef long long ll;
const int MOD = 1000000007;
using namespace std;

#pragma region mod
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

  // 入出力
  friend ostream& operator<<(ostream& s, const mint a) {
    s << a.x;
    return s;
  }
  friend istream& operator>>(istream& s, mint& a) {
    s >> a.x;
    return s;
  }
};

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
#pragma endregion

int main() {
  mint x = 1;
  x -= 2;
  cout << x << endl;
  x += 2;
  cout << x << endl;
}
